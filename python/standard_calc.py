import math


def bound_to_180(angle):
    """Bounds the provided angle between [-180, 180) degrees.

    e.g.)
        bound_to_180(135) = 135.0
        bound_to_180(200) = -160.0

    Args:
        angle (float): The input angle in degrees.

    Returns:
        float: The bounded angle in degrees.
    """
    angle_radians = math.radians(angle)

    bounded_angle_radians = 2 * math.atan(math.tan(0.5 * angle_radians))
    if round(math.degrees(bounded_angle_radians), 1) == 180.0:
        bounded_angle_radians *= -1

    return round(math.degrees(bounded_angle_radians), 1)


def is_angle_between(first_angle, middle_angle, second_angle):
    """Determines whether an angle is between two other angles.

   e.g.)
        is_angle_between(0, 45, 90) = True
        is_angle_between(45, 90, 270) = False

    Args:
        first_angle (float): The first bounding angle in degrees.
        middle_angle (float): The angle in question in degrees.
        second_angle (float): The second bounding angle in degrees.

    Returns:
        bool: True when `middle_angle` is not in the reflex angle of `first_angle` and `second_angle`, false otherwise.
    """
    # Checks for all conditions

    # Edge cases
    # (Since a reflex angle is less than 360 but greater than 180 so no reflex angle exists)
    angle_difference = abs(second_angle - first_angle)
    if angle_difference in [0, 180, 360]:
        return True

    normal_reflex = (abs(second_angle - first_angle) > 180)
    between_normal_angle = (second_angle > middle_angle > first_angle)

    # Logic joining conditions, here a simple XOR gate should be enough
    return normal_reflex ^ between_normal_angle
