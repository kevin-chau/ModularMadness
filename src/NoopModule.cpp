#include "NoopModule.h"

NoopModule::NoopModule(std::string name) : Module(name)
{

}

std::string NoopModule::process(std::string str)
{
  return str;
}
