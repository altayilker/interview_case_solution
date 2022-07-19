cmake_minimum_required(VERSION 3.22)
project(Interview-case)

set(CMAKE_C_STANDARD 99)

add_executable(Interview-case drivers/adc_driver/adc_driver.c drivers/adc_driver/adc_driver.h drivers/error_led/error_led.c drivers/error_led/error_led.h main.c torqueCalculations/digital_to_analog_conversion.c torqueCalculations/digital_to_analog_conversion.h torqueCalculations/analogVoltage_to_pedalAngle.c torqueCalculations/analogVoltage_to_pedalAngle.h torqueCalculations/torque_calculation.c torqueCalculations/torque_calculation.h)