/** @file
 *  @brief Header file for converting analog voltage input to pedal angle percentage
 *  it also includes moving average filter
 */

#ifndef INTERVIEW_CASE_ANALOGVOLTAGE_TO_PEDALANGLE_H
#define INTERVIEW_CASE_ANALOGVOLTAGE_TO_PEDALANGLE_H

#include "../drivers/adc_driver/adc_driver.h"
#include <stdio.h>

/** @brief Reads the adc channel id and analog voltage value
 *  and calculates pedal angle and then pedal angle percentage
 *  @param[in] id The ID of the ADC channel.
 *  @param[out] analog_voltage analog voltage after filtering
 *  @returns  Pedal angle percentage
 */
float analog_voltage_to_pedalAnglePercent(adc_channel_id_t id, const float* analog_voltage);

#endif //INTERVIEW_CASE_ANALOGVOLTAGE_TO_PEDALANGLE_H
