from standard_calc import bound_to_180, is_angle_between
import pytest


""" Tests for bound_to_180() """


@pytest.mark.parametrize("angle, expected", [
    (0, 0),
    (45, 45),
    (90, 90),
    (135, 135),
    (180, -180),
    (-0, -0),
    (-45, -45),
    (-90, -90),
    (-135, -135),
    (-180, -180),
    (300, -60),
    (-300, 60),
    (720, 0),
    (-720, 0),
    (540, -180),
    (-540, -180),
    (400, 40),
    (-400, -40),
    (225, -135),
    (-225, 135),
    (270, -90),
    (-270, 90),
    (315, -45),
    (-315, 45),
    (360, 0),
    (-360, 0),
    (405, 45),
    (-405, -45),
    (450, 90),
    (-450, -90)

])
def test_bound_to_180(angle, expected):
    assert bound_to_180(angle) == expected


""" Tests for is_angle_between() """


@pytest.mark.parametrize("first_angle, middle_angle, second_angle, expected", [
    (0, 1, 2, 1), 
    (90, 180, 190, 1),
    (45, 90, 135, 1), 
    (160, 0, 180, 0),
    (0, 90, 180, 1),
    (0, 180, 270, 0),
    (0, 270, 360, 1),
    (45, 90, 135, 1),
    (45, 135, 225, 1),
    (45, 225, 315, 0),
    (45, 315, 45, 1),
    ])
def test_between_basic1(first_angle, middle_angle, second_angle, expected):
    assert is_angle_between(first_angle, middle_angle, second_angle) == expected

