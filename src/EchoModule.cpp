#include "EchoModule.h"

EchoModule::EchoModule(std::string name) : Module(name)
{

}

std::string EchoModule::process(std::string str)
{
  return str+str;
}
