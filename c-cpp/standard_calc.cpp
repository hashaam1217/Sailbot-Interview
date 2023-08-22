#include "stdbool.h"
#include "standard_calc.h"
#include <iostream> 
#include <cmath>
#include <gtest/gtest.h>

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
    float angle_radians = angle * M_PI / 180;
    float bounded_angle= 2.0 * atan(tan(0.5 * angle_radians));

    //Edge case as -180 is included and 180 is not
    if (bounded_angle == -180.0)
    {
        bounded_angle*= -1;
    }

    //Conversion to degrees
    bounded_angle *= 180 / M_PI;

    bounded_angle = round(bounded_angle* 10 / 10);

    return bounded_angle;
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
    
    float angle_difference = abs(second_angle - first_angle);

    //Checks for edge case of a straight line where reflex would not exist
    if (angle_difference == 0.0 || angle_difference == 180.0 || angle_difference == 360.0)
    {
        return true;
    }

    bool normal_reflex = (angle_difference > 180);
    bool between_normal_angle = (second_angle > middle_angle && middle_angle > first_angle);

    //Relation can be simplified using a K-map, showing that it is a XOR gate
    return normal_reflex ^ between_normal_angle;
}


int main (void)
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
