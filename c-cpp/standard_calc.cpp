#include "stdbool.h"
#include "standard_calc.h"
#include <iostream> 
#include <cmath>

#define M_PI 3.14159265358979323846

using namespace std;

/**
 * @brief Bounds the provided angle between [-180, 180) degrees.
 *
 * e.g.)
 *      bound_to_180(135) = 135.0
 *      bound_to_180(200) = -160.0
 *
 * @param angle: The input angle in degrees.
 *
 * @return float: The bounded angle in degrees.
 */
float bound_to_180(float angle) {
    float angle_radians = angle * 180 / M_PI;
    float bounded_angle_radians = 2.0 * atan(tan(0.5 * angle_radians));
    
    bounded_angle_radians = round(bounded_angle_radians * 10 / 10);

    if (bounded_angle_radians == 180.0)
    {
        bounded_angle_radians *= -1;
    }

    return bounded_angle_radians;
}

/**
 * @brief Determines whether an angle is between two other angles
 *
 *  e.g.)
 *      is_angle_between(0, 45, 90) = true
 *      is_angle_between(45, 90, 270) = false
 * 
 * @param first_angle:  The first bounding angle in degrees.
 * @param middle_angle: The angle in question in degrees.
 * @param second_angle: The second bounding angle in degrees.
 * @return bool: TRUE when `middle_angle` is not in the reflex angle of `first_angle` and `second_angle`, FALSE otherwise
 */
bool is_angle_between(float first_angle, float middle_angle, float second_angle) {
    return true;
}
