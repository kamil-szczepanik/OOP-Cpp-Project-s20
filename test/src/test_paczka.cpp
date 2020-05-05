#include "gtest/gtest.h"

#include "paczka.h"

TEST(PaczkaTest, Sample) {
  EXPECT_EQ(1 + 1, 2);
}

TEST(PaczkaTest, Sample2) {
  EXPECT_EQ(getInt(), 5);
}

TEST(PaczkaTest, Sample3) {
  EXPECT_EQ(getAnotherInt(), 125);
}