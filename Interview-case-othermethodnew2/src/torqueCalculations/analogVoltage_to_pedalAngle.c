/** @file
 *  @brief Header file for converting analog voltage input to pedal angle percentage
 *  it also includes moving average filter
 */

#include "analogVoltage_to_pedalAngle.h"

#define pedal_angle_interval pedal_angle_max - pedal_angle_min

float analog_voltage_to_pedalAnglePercent(adc_channel_id_t id, const float* analog_voltage)
{
    float pedal_angle = 0;
    float pedal_angle_percent = 0;

    if(id == ADC_CHANNEL0)
        pedal_angle = ((*analog_voltage) - 0.5)/0.1;
    else
        pedal_angle = ((*analog_voltage) - 1.0)/ 0.08;

    int pedal_angle_max = 30;
    int pedal_angle_min = 0;

    pedal_angle_percent = pedal_angle*100/pedal_angle_interval;
    printf("pedal angle : %f [deg]\n", pedal_angle);
    printf("pedal angle percentage : %f [percentage]\n", pedal_angle_percent);
    return pedal_angle_percent;
}

