#include "gtest/gtest.h"
#include "ModuleTest.h"
#include "EchoModuleTest.h"
#include "ReverseModuleTest.h"
#include "NoopModuleTest.h"
#include "DelayModuleTest.h"
#include "ModularMadnessTest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
