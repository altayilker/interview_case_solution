/** @file
 *  @brief Header file for a digital to analog voltage conversion.
 *  it also includes moving average filter
 */

#include "digital_to_analog_conversion.h"

static float arr[] = {0, 0, 0};
static int flag = 0;
static int flag_previous = 0;


float analog_voltage_filtering(const adc_value_t* value, float adc, adc_channel_id_t id)
{
    float analog_voltage = adc;
    printf("[ADC] channel id : %i [volt] and corresponding analog voltage : %f [volt] is selected to calculate torque\n", id, analog_voltage);

    arr[flag] = analog_voltage;
    flag_previous = flag;

    flag = flag +1;
    if(flag > 2) {
        flag = flag % 3;
    }

    int K = 3;
    analog_voltage = compute_moving_average(arr, K);
    arr[flag_previous] = analog_voltage;

    printf("analog voltage after filtering : %f [volt]\n", analog_voltage);

    //for(int i = 0; i < 3; i++)
    //    printf( " arr[] : %f\n", arr[i]);
    return analog_voltage;
}

float compute_moving_average(const float arr[], int K)
{
    float sum = 0;

    for (int i = 0; i < K; i++)
        sum += arr[i];

    // printf( "sum / float(K) : %f \n" , sum / (float)K);
    return sum / (float)K;
}

