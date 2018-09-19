#ifndef __MODULE_H__
#define __MODULE_H__

#include <string>
#include <vector>

/// @brief Module base class
class Module
{
public:
  /// @brief User-given module name
  std::string m_name;

  /// @brief input modules
  std::vector<Module*> m_input_connections;

  /// @brief output module
  Module * m_output_connection = NULL;

  /// @brief Constructor
  Module(std::string name);

  /// @brief Destructor
  ~Module();

  ///
  void connectOutputTo(Module * m);

  void connectInputTo(Module * m);

  virtual std::string process(std::string str);
};


#endif /* #ifndef __MODULE_H__ */
