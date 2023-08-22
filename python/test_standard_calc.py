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


def test_between_basic1():
    assert is_angle_between(0, 1, 2)
