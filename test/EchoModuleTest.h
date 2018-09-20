#include "EchoModule.h"

// The fixture for testing class EchoModule.
class EchoModuleTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  EchoModuleTest() {
     // You can do set-up work for each test here.
  }

  ~EchoModuleTest() override {
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

  // Objects declared here can be used by all tests in the test case for EchoModule.
};

// Tests name member
TEST_F(EchoModuleTest, process)
{
  EchoModule m("My Echo Module");

  ASSERT_EQ(m.process("Hello"), "HelloHello");
}

TEST_F(EchoModuleTest, operation)
{
  EchoModule m("My Echo Module");

  // First output is "hello"
  ASSERT_EQ(m.m_operation, Module::ECHO);
}
