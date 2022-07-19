/** @file
 *  @brief Source file for a (dummy) ADC driver.
 */

#include "adc_driver.h"
#include "../../torqueCalculations/digital_to_analog_conversion.h"
#include "../error_led/error_led.h"

#include <stdio.h>



void adc_read_set_output(adc_channel_id_t id, adc_value_t value,
                    adc_return_t return_value) {
  if (id < ADC_NUM_CHANNELS) {
    adc_read_values[id] = value;
    adc_read_return_value[id] = return_value;
  }
}

adc_return_t adc_init(adc_channel_id_t id) {
  printf("[ADC] Initializing channel %i\n", id);
  return ADC_RET_OK;
}

adc_return_t adc_read(adc_channel_id_t id, adc_value_t* value) {
  *value = adc_read_values[id];
  adc_return_t return_value = adc_read_return_value[id];

  printf("[ADC] Reading channel %i = %u. Ret = %i\n", id, *value, return_value);

  return return_value;
}

adc_return_t adc_check_adc_value(float adc, adc_channel_id_t id)
{

    if(id == ADC_CHANNEL0) {
        if ((adc >= 0.5) && (adc <= 3.5 ))
            return ADC_RET_OK;
        else
            return ADC_RET_NOK;}
    else{
        if ((adc >= 1) && (adc <= 3.4))
            return ADC_RET_OK;
        else
            return ADC_RET_NOK;
    }
}


