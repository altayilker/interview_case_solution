/** @file
 *  @brief Header file for a digital to analog voltage conversion.
 *  it also includes moving average filter
 */

#ifndef INTERVIEW_CASE_DIGITAL_TO_ANALOG_CONVERSION_H
#define INTERVIEW_CASE_DIGITAL_TO_ANALOG_CONVERSION_H

#include <stdio.h>
#include "../drivers/adc_driver/adc_driver.h"


/** @brief Starts filtering process and calls moving average filter
 *  @param[in] adc Analog ADC value
 *  @param[in] id The ID of the ADC channel.
 *  @param[out] value The read ADC value, which is a value between 0 and 1023.
 *  @returns analog voltage after filtering.
 */
float analog_voltage_filtering(const adc_value_t* value, float adc, adc_channel_id_t id);

/** @brief Computes moving average of input array elements.
 *  @param[in] arr[] The array that holds one current and 2 previous analog voltage values.
 *  @param[in] K Window size of moving average filter.
 *  @returns analog voltage after filtering to use in analog_voltage_filtering function.
 */
float compute_moving_average(const float arr[], int K);


#endif //INTERVIEW_CASE_DIGITAL_TO_ANALOG_CONVERSION_H
