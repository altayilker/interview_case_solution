/** @file
 *  @brief Header file for interpolate torque for different speeds
 */

#include "torque_calculation.h"
#include <stdio.h>

void midpoints_calculator(int car_velocity){

    int n = sizeof(f1)/sizeof(f1[0]);

    float speed_n = car_velocity + 1;
    for(int i = 0; i < n; i++) {
        float interval = (f1[i].y - f2[i].y) / 50;
        f3[i].x = f1[i].x;
        f3[i].y = f1[i].y - interval * speed_n;
        //printf("f3[i].x : %f\n", f3[i].x);
        //printf("f3[i].y : %f\n", f3[i].y);
    }
}


float interpolate(int pedal_angle_percent, int car_velocity)  {

    int n = sizeof(f1)/sizeof(f1[0]);

    int xi = pedal_angle_percent;
    float result = 0; // Initialize result
    struct Data* f = f3;

    for (int i=0; i<n; i++)
    {
        float term = f[i].y;
        for (int j=0;j<n;j++)
        {
            if (j!=i)
                term = term*(xi - f[j].x)/(float)(f[i].x - f[j].x);
        }

        result += term;
    }
    printf("torque: %f [Nm]\n", result);

    return result;
}


void calc_torque(int pedal_angle_percent, int car_velocity)
{
    midpoints_calculator(car_velocity);
    interpolate(pedal_angle_percent, car_velocity);
}
