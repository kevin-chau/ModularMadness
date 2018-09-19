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
  ~ModularMadness();

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

  ///
  static void process(std::string str);

private:
  // Map of modules, keyed by name
  static std::map<std::string, Module *> m_modules;

  // First module defined
  static Module * m_first_module;
};

#endif /* #ifndef __MODULAR_MADNESS_H__ */
