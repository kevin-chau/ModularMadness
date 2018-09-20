#include "ModularMadness.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

map<string, Module*> ModularMadness::m_modules;
Module * ModularMadness::m_first_module = NULL;

void ModularMadness::defineModule(string name, string operation)
{
  if (operation == "echo")
  {
    // Create EchoModule
    EchoModule * em = new EchoModule(name);

    // Push to map of modules
    m_modules.insert(pair<string,Module*>(name, em));

    // Check if first module defined
    if (m_first_module == NULL)
    {
      // Save a pointer to the first module
      m_first_module = em;
    }
  }
  else if (operation == "delay")
  {
    // Create DelayModule
    DelayModule * dm = new DelayModule(name);

    // Push to map of modules
    m_modules.insert(pair<string,Module*>(name, dm));

    // Check if first module defined
    if (m_first_module == NULL)
    {
      // Save a pointer to the first module
      m_first_module = dm;
    }
  }
  else if (operation == "noop")
  {
    // Create NoopModule
    NoopModule * nm = new NoopModule(name);

    // Push to map of modules
    m_modules.insert(pair<string,Module*>(name, nm));

    // Check if first module defined
    if (m_first_module == NULL)
    {
      // Save a pointer to the first module
      m_first_module = nm;
    }
  }
  else if (operation == "reverse")
  {
    // Create ReverseModule
    ReverseModule * rm = new ReverseModule(name);

    // Push to map of modules
    m_modules.insert(pair<string,Module*>(name, rm));

    // Check if first module defined
    if (m_first_module == NULL)
    {
      // Save a pointer to the first module
      m_first_module = rm;
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
      // Handle the "module" command
      handleModuleCommand();
    }
    // Check if the command is a connect command
    else if (command == "connect")
    {
      // Handle the "connect" command
      handleConnectCommand();
    }
    // Check if the command is a process command
    else if (command == "process")
    {
      // Get the input strings
      string input_line;
      getline(cin, input_line);

      // Handle the "process" command
      handleProcessCommand(input_line);

      // Output new line character
      cout << endl;
    }
  }
}

void ModularMadness::connectModules(string module_name1, string module_name2)
{
  // Lookup the modules by name
  Module * m1 = m_modules.find(module_name1)->second;
  Module * m2 = m_modules.find(module_name2)->second;

  // Connect the modules
  m1->connectOutputTo(m2);
}

void ModularMadness::process(string str)
{
  Module * m = m_first_module;

  string output;
  string input = str;

  // Loop through modules
  while (m != NULL)
  {
    // Process the input from the previous module
    output = m->process(input);

    // Make the output of the current module the input o the next module
    input = output;

    // Iterate to the next module
    m = m->m_output_connection;
  }

  // Print to screen
  cout << output;
}

/// @brief handle the "module" command
void ModularMadness::handleModuleCommand()
{
  // Read in the module name
  string name;
  cin >> name;

  // Read in the operation
  string operation;
  cin >> operation;

  defineModule(name, operation);
}

/// @brief handle the "connect" command
void ModularMadness::handleConnectCommand()
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

/// @brief handle the "process" command
void ModularMadness::handleProcessCommand(string input_line)
{
  // Tokenize the input strings
  istringstream iss(input_line);
  vector<string> tokens{istream_iterator<string>{iss},
                  istream_iterator<string>{}};
  for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
  {
    // Process the token
    process(*it);

    // Check if there's another token
    if ((it+1) != tokens.end())
    {
      // Output a space before the next output string
      cout << " ";
    }
  }

  // Search for a delay module in the stream
  Module * m = m_first_module;
  while (m != NULL)
  {
    // look for DELAY operation type
    if (m->m_operation == Module::DELAY)
    {
      // Output a space before the last output string
      cout << " ";

      // Process empty dummy string
      process("");

      // Reset the delay module
      ((DelayModule*)m)->reset();
    }

    // Iterate to the next module
    m = m->m_output_connection;
  }
}
