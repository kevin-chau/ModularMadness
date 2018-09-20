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

// Tests the program example in the spec
// Example Input
//   module alpha reverse
//   module beta delay
//   connect alpha beta
//   process hello world
// Output
//   hello olleh dlrow
TEST_F(ModularMadnessTest, example)
{
  // Simulates standard input: "module alpha reverse"
  ModularMadness::defineModule("alpha", "reverse");

  // Simulates standard input: "module beta delay"
  ModularMadness::defineModule("beta", "delay");

  // Simulates standard input: "connect alpha beta"
  ModularMadness::connectModules("alpha", "beta");

  // Start capturing standard out
  testing::internal::CaptureStdout();

  // Simulates standard input: "process hello world"
  ModularMadness::handleProcessCommand("hello world");

  // Get the captured output
  std::string output = testing::internal::GetCapturedStdout();

  // Assert equal to the expect example output
  ASSERT_EQ(output, "hello olleh dlrow");

  // Reset the ModularMadness class
  ModularMadness::reset();
}

// Tests multiple process commands, which should "behave the same way as if input alone"
// Example Input
//   module alpha reverse
//   module beta delay
//   connect alpha beta
//   process hello world
//   process hello world
// Output
//   hello olleh dlrow
//   hello olleh dlrow
TEST_F(ModularMadnessTest, double_process)
{
  // Simulates standard input: "module alpha reverse"
  ModularMadness::defineModule("alpha", "reverse");

  // Simulates standard input: "module beta delay"
  ModularMadness::defineModule("beta", "delay");

  // Simulates standard input: "connect alpha beta"
  ModularMadness::connectModules("alpha", "beta");

  // Start capturing standard out
  testing::internal::CaptureStdout();

  // Simulates standard input: "process hello world"
  ModularMadness::handleProcessCommand("hello world");

  // Get the captured output
  std::string output = testing::internal::GetCapturedStdout();

  // Assert equal to the expect example output
  ASSERT_EQ(output, "hello olleh dlrow");

  // Start capturing standard out
  testing::internal::CaptureStdout();

  // Simulates standard input: "process hello world"
  ModularMadness::handleProcessCommand("hello world");

  // Get the captured output
  output = testing::internal::GetCapturedStdout();

  // Assert equal to the expect example output
  ASSERT_EQ(output, "hello olleh dlrow");

  // Reset the ModularMadness class
  ModularMadness::reset();
}

// Tests multiple process commands, which should "behave the same way as if input alone"
// Example Input
//   module a echo
//   module b echo
//   module c echo
//   connect a b
//   connect b c
//   process hello world
//   process hello world
// Output
//   hellohellohellohellohellohellohellohello worldworldworldworldworldworldworldworld
//   hellohellohellohellohellohellohellohello worldworldworldworldworldworldworldworld
TEST_F(ModularMadnessTest, three_echos)
{
  // Simulates standard input: "module a echo"
  ModularMadness::defineModule("a", "echo");

  // Simulates standard input: "module b echo"
  ModularMadness::defineModule("b", "echo");

  // Simulates standard input: "module c echo"
  ModularMadness::defineModule("c", "echo");

  // Simulates standard input: "connect a b"
  ModularMadness::connectModules("a", "b");

  // Simulates standard input: "connect b c"
  ModularMadness::connectModules("b", "c");

  // Start capturing standard out
  testing::internal::CaptureStdout();

  // Simulates standard input: "process hello world"
  ModularMadness::handleProcessCommand("hello world");

  // Get the captured output
  std::string output = testing::internal::GetCapturedStdout();

  // Assert equal to the expect example output
  ASSERT_EQ(output, "hellohellohellohellohellohellohellohello worldworldworldworldworldworldworldworld");

  // Start capturing standard out
  testing::internal::CaptureStdout();

  // Simulates standard input: "process hello world"
  ModularMadness::handleProcessCommand("hello world");

  // Get the captured output
  output = testing::internal::GetCapturedStdout();

  // Assert equal to the expect example output
  ASSERT_EQ(output, "hellohellohellohellohellohellohellohello worldworldworldworldworldworldworldworld");

  // Reset the ModularMadness class
  ModularMadness::reset();
}


// Tests multiple process commands, which should "behave the same way as if input alone"
// Example Input
//   module a noop
//   module b noop
//   connect a b
//   process hello world
// Output
//   hello world
TEST_F(ModularMadnessTest, two_noops)
{
  // Simulates standard input: "module a echo"
  ModularMadness::defineModule("a", "noop");

  // Simulates standard input: "module b echo"
  ModularMadness::defineModule("b", "noop");

  // Simulates standard input: "connect a b"
  ModularMadness::connectModules("a", "b");

  // Start capturing standard out
  testing::internal::CaptureStdout();

  // Simulates standard input: "process hello world"
  ModularMadness::handleProcessCommand("hello world");

  // Get the captured output
  std::string output = testing::internal::GetCapturedStdout();

  // Assert equal to the expect example output
  ASSERT_EQ(output, "hello world");

  // Reset the ModularMadness class
  ModularMadness::reset();
}
