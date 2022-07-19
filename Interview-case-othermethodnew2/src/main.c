/** @file
 *  @brief Main file.
 *  @description Just contains some example code. Adapt it in the way you like.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "drivers/adc_driver/adc_driver.h"
#include "drivers/error_led/error_led.h"
#include "torqueCalculations/digital_to_analog_conversion.h"
#include "torqueCalculations/analogVoltage_to_pedalAngle.h"
#include "torqueCalculations/torque_calculation.h"


int main(int argc, char *argv[]) {

  adc_value_t value = 0;
  error_led_init();

  srand((unsigned int)time(NULL));
  float angle_interval = 30.0;
  float random_pedal_angle = 0;

  adc_init(ADC_CHANNEL0);
  adc_init(ADC_CHANNEL1);
  printf("\n\n");

  int i = 1;
  while(1)
  {
    if(i == 9) // increase to see more iterations
        break; // exit loop

      if( i%5 == 0)
          random_pedal_angle = ((float)rand()/(float)(RAND_MAX)) * angle_interval + 31;
      else
          random_pedal_angle = ((float)rand()/(float)(RAND_MAX)) * angle_interval;

      printf("random_pedal_angle : %f [deg]\n", random_pedal_angle);

      float adc1 = 0.5 + 0.1 * random_pedal_angle;
      float adc2 = 1.0 + 0.08 * random_pedal_angle;

      printf("adc1: %f [volt]\n", adc1);
      printf("adc2: %f [volt]\n", adc2);

      adc_return_t ADC_RET_STATUS_0 = adc_check_adc_value(adc1, ADC_CHANNEL0);
      adc_return_t ADC_RET_STATUS_1 = adc_check_adc_value(adc2, ADC_CHANNEL1);

      adc_value_t adc1_value = adc1*1024/5;
      adc_value_t adc2_value = adc2*1024/5;

      adc_read_set_output(ADC_CHANNEL0, adc1_value , ADC_RET_STATUS_0);
      adc_read_set_output(ADC_CHANNEL1, adc2_value , ADC_RET_STATUS_1);

      adc_read(ADC_CHANNEL0, &value);
      adc_read(ADC_CHANNEL1, &value);

      float adc1_filtered = analog_voltage_filtering(&adc1_value, adc1, ADC_CHANNEL0);
      float adc2_filtered = analog_voltage_filtering(&adc2_value, adc2, ADC_CHANNEL1);

      adc_return_t ADC_RET_STATUS_0_2 = adc_check_adc_value(adc1_filtered, ADC_CHANNEL0);
      adc_return_t ADC_RET_STATUS_1_2 = adc_check_adc_value(adc2_filtered, ADC_CHANNEL1);

      if(ADC_RET_STATUS_0 == ADC_RET_NOK || ADC_RET_STATUS_1 == ADC_RET_NOK || ADC_RET_STATUS_0_2 == ADC_RET_NOK || ADC_RET_STATUS_1_2 == ADC_RET_NOK){
          printf("channel is unsuccessful \n");
          error_led_set(true);
      }
      else{
          error_led_set(false);
          float pedal_angle_percent = analog_voltage_to_pedalAnglePercent(ADC_CHANNEL0, &adc1_filtered);

          int car_velocity = rand() % 51;
          printf("car_velocity  : %i [km/h] \n", car_velocity);

          calc_torque(pedal_angle_percent, car_velocity);
      }
      i++;
      printf("\n\n");
  }

}
