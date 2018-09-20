#ifndef __MODULAR_MADNESS_H__
#define __MODULAR_MADNESS_H__

// Include modules
#include "Module.h"
#include "DelayModule.h"
#include "EchoModule.h"
#include "NoopModule.h"
#include "ReverseModule.h"
#include <map>

/// @brief ModularMadness class
class ModularMadness
{
public:
  ModularMadness();
  ~ModularMadness()
  {
    reset();
  }

  /// main loop
  static void loop();

  /// @brief Define a module
  /// @param[in] name - the name of the module
  /// @param[in] operation - the operation type of the module
  /// @return void
  static void defineModule(std::string name, std::string operation);

  /// @brief Define a connection from module1 to module2.
  ///        The output of module1 will be routed to the input module2.
  /// @param[in] module_name1 - the name of module1
  /// @param[in] module_name2 - the name of module2
  /// @return void
  static void connectModules(std::string module_name1, std::string module_name2);

  /// @brief send a string through the module stream
  ///
  /// @param[in] str - the string to input into the module stream
  /// @return void
  static void process(std::string str);

  /// @brief handle the "process" command
  ///
  /// @param[in] input_line - the input strings to be processed
  /// @return void
  static void handleProcessCommand(std::string input_line);

  /// @reset this class (clear the modules map)
  static void reset()
  {
    // Reset the first module pointer
    m_first_module = NULL;

    // Loop through the map for cleanup
    for (std::map<std::string,Module *>::iterator it=m_modules.begin(); it!=m_modules.end(); ++it)
    {
      // Delete each module
      delete it->second;
    }

    // Clear the map
    m_modules.clear();
  }

private:
  /// @brief handle the "module" command
  static void handleModuleCommand();

  /// @brief handle the "connect" command
  static void handleConnectCommand();

  // Map of modules, keyed by name
  static std::map<std::string, Module *> m_modules;

  // First module defined
  static Module * m_first_module;
};

#endif /* #ifndef __MODULAR_MADNESS_H__ */
