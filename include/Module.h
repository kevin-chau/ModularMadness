#ifndef __MODULE_H__
#define __MODULE_H__

#include <string>

/// @brief Module base class
class Module
{
public:
  std::string m_name;

  Module(std::string name);

  ~Module();
};


#endif /* #ifndef __MODULE_H__ */
