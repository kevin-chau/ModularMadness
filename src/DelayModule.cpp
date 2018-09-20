#include "DelayModule.h"

DelayModule::DelayModule(std::string name) : Module(name)
{
  m_operation = Module::DELAY;
}

std::string DelayModule::process(std::string str)
{
  // Copy the previous string into a temp variable to be returned
  std::string temp = m_previousStr;

  // Update the previous string
  m_previousStr = str;

  // Return old (temp) previous string
  return temp;
}
