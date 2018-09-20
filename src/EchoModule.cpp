#include "EchoModule.h"

EchoModule::EchoModule(std::string name) : Module(name)
{
  m_operation = Module::ECHO;
}

std::string EchoModule::process(std::string str)
{
  return str+str;
}
