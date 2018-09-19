#include "Module.h"

Module::Module(std::string name)
{
  m_name = name;
}

Module::~Module()
{

}

void Module::connectOutputTo(Module * m)
{
  // Make the forward link
  m_output_connection = m;

  // Make the reverse link
  m->m_input_connections.push_back(this);
}

void Module::connectInputTo(Module * m)
{
  // Make the forward link
  m->m_output_connection = this;

  // Make the reverse link
  this->m_input_connections.push_back(m);
}

std::string Module::process(std::string str)
{
  return "???";
}
