#include "gtest/gtest.h"
#include "ModuleTest.h"
#include "EchoModuleTest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
