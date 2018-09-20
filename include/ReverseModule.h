#ifndef __REVERSE_MODULE_H__
#define __REVERSE_MODULE_H__

#include "Module.h"

/// @brief Reverse Module
class ReverseModule : public Module
{
public:
  ReverseModule(std::string);

  // Process function should reverse the input string
  // ex:
  //    in - "Hello"
  //    out - "olleH"
  virtual std::string process(std::string str);
};

#endif /* #ifndef __REVERSE_MODULE_H__ */
