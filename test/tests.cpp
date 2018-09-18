#include "gtest/gtest.h"

TEST(HELLO, HI)
{
  ASSERT_TRUE(false);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
