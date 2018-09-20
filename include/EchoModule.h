#ifndef __ECHO_MODULE_H__
#define __ECHO_MODULE_H__

#include "Module.h"

/// @brief Echo Module
class EchoModule : public Module
{
public:
  EchoModule(std::string);

  // Process function should echo the input string
  // ex:
  //    in - "Hello"
  //    out - "HelloHello"
  virtual std::string process(std::string str);
};

#endif /* #ifndef __ECHO_MODULE_H__ */
