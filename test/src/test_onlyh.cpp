#include "gtest/gtest.h"

#include "onlyh.h"

TEST(OnlyhTest, SampleTest) {
  EXPECT_EQ(getStr(), "abc");
}