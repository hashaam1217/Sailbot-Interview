#include "gtest/gtest.h"
#include "standard_calc.cpp"

TEST(BoundTo180Test, PositiveInput) {
  EXPECT_EQ(bound_to_180(0), 0);
  EXPECT_EQ(bound_to_180(45), 45);
  EXPECT_EQ(bound_to_180(90), 90);
  EXPECT_EQ(bound_to_180(135), 135);
}

TEST(BoundTo180Test, NegativeInput) {
  EXPECT_EQ(bound_to_180(-0), 0);
  EXPECT_EQ(bound_to_180(-45), -45);
  EXPECT_EQ(bound_to_180(-90), -90);
  EXPECT_EQ(bound_to_180(-135), -135);
}

TEST(BoundTo180Test, PositiveLargeInput) {
  EXPECT_EQ(bound_to_180(300), -60);
  EXPECT_EQ(bound_to_180(540), -180);
  EXPECT_EQ(bound_to_180(400), 40);
  EXPECT_EQ(bound_to_180(270), -90);
}

TEST(BoundTo180Test, NegativeLargeInput) {
  EXPECT_EQ(bound_to_180(-300), 60);
  EXPECT_EQ(bound_to_180(-540), 180);
  EXPECT_EQ(bound_to_180(-400), -40);
  EXPECT_EQ(bound_to_180(-270), 90);
}

TEST(BoundTo180Test, ZeroDegreeAngles) {
  EXPECT_EQ(bound_to_180(180), -180);
  EXPECT_EQ(bound_to_180(0), 0);
  EXPECT_EQ(bound_to_180(720), 0);
  EXPECT_EQ(bound_to_180(540), -180);
}

TEST(IsAngleBetweenTest, PositiveInput) {
  EXPECT_EQ(is_angle_between(001, 002, 001), 1);
  EXPECT_EQ(is_angle_between(90, 180, 190), 1);
  EXPECT_EQ(is_angle_between(040, 90, 135), 1);
  EXPECT_EQ(is_angle_between(160, 000, 180), 0);
  EXPECT_EQ(is_angle_between(000, 180, 270), 0);
}


TEST(IsAngleBetweenTest, ZeroDegreeAngles) {
  EXPECT_TRUE(is_angle_between(045, 315, 045));
  EXPECT_TRUE(is_angle_between(180, 072, 180));
  EXPECT_TRUE(is_angle_between(000, 000, 360));
  EXPECT_TRUE(is_angle_between(90, 000, 270));
}
