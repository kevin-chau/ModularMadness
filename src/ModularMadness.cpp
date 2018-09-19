#include "ModularMadness.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

std::map<std::string, Module> ModularMadness::modules;

void ModularMadness::defineModule(string name, string operation)
{
  if (operation == "echo")
  {
    // Create EchoModule
    EchoModule m(name);

    // Push to map of modules
    modules.insert(pair<string,Module>(name, m));
  }
  else if (operation == "delay")
  {
    // Create DelayModule
    DelayModule m(name);

    // Push to map of modules
    modules.insert(pair<string,Module>(name, m));
  }
  else if (operation == "noop")
  {
    // Create NoopModule
    NoopModule m(name);

    // Push to map of modules
    modules.insert(pair<string,Module>(name, m));
  }
  else if (operation == "reverse")
  {
    // Create ReverseModule
    ReverseModule m(name);

    // Push to map of modules
    modules.insert(pair<string,Module>(name, m));
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

    }
  }
}

void ModularMadness::connectModules(std::string module_name1, std::string module_name2)
{
  // Connect the modules
}

int main()
{
  cout << "Welcome to Modular Madness!" << endl;

  // Loop on forever
  ModularMadness::loop();

  return 0;
}
