#include "Module.h"
#include "ReverseModule.h"

// The fixture for testing class Module.
class ModuleTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  ModuleTest() {
     // You can do set-up work for each test here.
  }

  ~ModuleTest() override {
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

  // Objects declared here can be used by all tests in the test case for Module.
};

// Tests name member
TEST_F(ModuleTest, connectOutputTo)
{
  Module m1("My Module 1");
  Module m2("My Module 2");

  m1.connectOutputTo(&m2);

  ASSERT_EQ(m1.m_output_connection->m_name, "My Module 2");

  ASSERT_EQ(m2.m_input_connections[0]->m_name, "My Module 1");
}

// Tests name member
TEST_F(ModuleTest, connectInputTo)
{
  Module m1("My Module 1");
  Module m2("My Module 2");

  m1.connectInputTo(&m2);

  ASSERT_EQ(m1.m_input_connections[0]->m_name, "My Module 2");

  ASSERT_EQ(m2.m_output_connection->m_name, "My Module 1");
}

// Tests name member
TEST_F(ModuleTest, virtual1)
{
  ReverseModule * m1 = new ReverseModule("My Module 1");
  Module * m2 = m1;

  ASSERT_EQ("olleh", m2->process("hello"));
}

TEST_F(ModuleTest, virtual2)
{
  ReverseModule m1("My Module 1");
  Module * m2 = &m1;
  Module * m3 = m2;

  ASSERT_EQ("olleh", m3->process("hello"));
}
