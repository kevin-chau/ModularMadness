#include "ReverseModule.h"
#include <algorithm>

ReverseModule::ReverseModule(std::string name) : Module(name)
{
  m_operation = Module::REVERSE;
}

std::string ReverseModule::process(std::string str)
{
  // Reverse the string
  std::reverse(str.begin(), str.end());

  return str;
}
