/** @file
 *  @brief Header file for interpolating torque values for different speeds
 */

#ifndef INTERVIEW_CASE_TORQUE_CALCULATION_H
#define INTERVIEW_CASE_TORQUE_CALCULATION_H

/** @brief Structure that holds torque-pedal angle graph values. */
struct Data
{
    float x, y;
};

/** @brief f1 holds torque-pedal angle values for 0 km/h */
static struct Data f1[] = {{0,0}, {10,18}, {20,35}, {30,50}, {40,62}, {60,82}, {80,103}, {100,120}};
/** @brief f2 holds torque-pedal angle values for 50 km/h car velocity */
static struct Data f2[] = {{0,-30}, {10,-10}, {20,10}, {30,30}, {40,45}, {60,72}, {80,95}, {100,120}};
/** @brief f2 holds torque-pedal angle values for a randomly generated car velocity between 0 - 50 km/h car velocity*/
static struct Data f3[8];

/** @brief Finds the midpoints of given torque values corresponding pedal angle
 * for car velocities between 0 - 50 km/h from the given torque-pedal angle graph.
 *  @param[in] car_velocity The car velocity.
 */
void midpoints_calculator(int car_velocity);

/** @brief Interpolates using the midpoints of torque values
 *  for a randomly generated car velocity between 0 - 50 km/h equally divided.
 *  @param[in] pedal_angle_percent Pedal angle percentage.
 *  @param[in] car_velocity The car velocity.
 *  @returns torque value for any given car velocity.
 */
float interpolate(int pedal_angle_percent, int car_velocity);

/** @brief calls midpoints_calculator and interpolate function respectively.
 *  @param[in] pedal_angle_percent Pedal angle percentage.
 *  @param[in] car_velocity The car velocity.
 */
void calc_torque(int pedal_angle_percent, int car_velocity);


#endif //INTERVIEW_CASE_TORQUE_CALCULATION_H
