#ifndef __NOOP_MODULE_H__
#define __NOOP_MODULE_H__

#include "Module.h"

/// @brief Noop Module
class NoopModule : public Module
{
public:
  NoopModule(std::string);

  // Process function should NOOP the input string
  // ex:
  //    in - "Hello"
  //    out - "Hello"
  virtual std::string process(std::string str);
};

#endif /* #ifndef __NOOP_MODULE_H__ */
