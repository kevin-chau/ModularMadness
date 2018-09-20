#include "ModularMadness.h"

// The fixture for testing class ModularMadness.
class ModularMadnessTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  ModularMadnessTest() {
     // You can do set-up work for each test here.
  }

  ~ModularMadnessTest() override {
     // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override {
     // Code here will be called immediately after the constructor (right
     // before each test).
  }

  void TearDown() override {
     // Code here will be called immediately after each test (right
     // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for ModularMadness.
};

// Tests process function
TEST_F(ModularMadnessTest, example)
{
  // Simulates standard input: "module alpha reverse"
  defineModule("alpha", "reverse");

  // Simulates standard input: "module beta delay"
  defineModule("beta", "delay");

  // Simulates standard input: "connect alpha beta"
  connectModules("alpha", "beta");

  // Simulates standard input: "process hello world"
  defineModule("alpha", "reverse")l
}
