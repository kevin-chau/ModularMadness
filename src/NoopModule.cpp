#include "NoopModule.h"

NoopModule::NoopModule(std::string name) : Module(name)
{
  m_operation = Module::NOOP;
}

std::string NoopModule::process(std::string str)
{
  return str;
}
