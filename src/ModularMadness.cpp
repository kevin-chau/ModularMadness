#include "ModularMadness.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

map<string, Module> ModularMadness::m_modules;
Module * ModularMadness::m_first_module = NULL;

void ModularMadness::defineModule(string name, string operation)
{
  if (operation == "echo")
  {
    // Create EchoModule
    EchoModule m(name);

    // Push to map of modules
    m_modules.insert(pair<string,Module>(name, m));

    // Check if first module defined
    if (m_first_module == NULL)
    {
      // Save a pointer to the first module
      m_first_module = &m;
    }
  }
  else if (operation == "delay")
  {
    // Create DelayModule
    DelayModule m(name);

    // Push to map of modules
    m_modules.insert(pair<string,Module>(name, m));

    // Check if first module defined
    if (m_first_module == NULL)
    {
      // Save a pointer to the first module
      m_first_module = &m;
    }
  }
  else if (operation == "noop")
  {
    // Create NoopModule
    NoopModule m(name);

    // Push to map of modules
    m_modules.insert(pair<string,Module>(name, m));

    // Check if first module defined
    if (m_first_module == NULL)
    {
      // Save a pointer to the first module
      m_first_module = &m;
    }
  }
  else if (operation == "reverse")
  {
    // Create ReverseModule
    ReverseModule m(name);

    // Push to map of modules
    m_modules.insert(pair<string,Module>(name, m));

    // Check if first module defined
    if (m_first_module == NULL)
    {
      // Save a pointer to the first module
      m_first_module = &m;
    }
  }
}

void ModularMadness::loop()
{
  // Loop on standard input forever
  while(1)
  {
    // Read the first token
    string command;
    cin >> command;

    // Check if the command is a module definition command
    if (command == "module")
    {
      // Read in the module name
      string name;
      cin >> name;

      // Read in the operation
      string operation;
      cin >> operation;

      defineModule(name, operation);
    }
    // Check if the command is a connect command
    else if (command == "connect")
    {
      // Read in the first module name
      string module_name1;
      cin >> module_name1;

      // Read in the second module name
      string module_name2;
      cin >> module_name2;

      // Connect the modules
      connectModules(module_name1, module_name2);
    }
    // Check if the command is a process command
    else if (command == "process")
    {
      // Get the input strings
      string input_line;
      getline(cin, input_line);

      istringstream iss(input_line);
      vector<string> tokens{istream_iterator<string>{iss},
                      istream_iterator<string>{}};
      for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
      {
        process(*it);
      }
    }
  }
}

void ModularMadness::connectModules(string module_name1, string module_name2)
{
  // Lookup the modules by name
  Module m1 = m_modules.find(module_name1)->second;
  Module m2 = m_modules.find(module_name2)->second;

  // Connect the modules
  m1.connectOutputTo(&m2);
}

void ModularMadness::process(string str)
{
  Module * m = m_first_module;

  string output;
  string input = str;

  // Loop through modules
  while (m != NULL)
  {
    cout << "Name: " << m->m_name << endl;
    // output = m->process(input);
    // cout << "Output: " << output << endl;
    // input = output;
    m = m->m_output_connection;
  }

  // cout << output << endl;

}

int main()
{
  cout << "Welcome to Modular Madness!" << endl;

  // Loop on forever
  ModularMadness::loop();

  return 0;
}
