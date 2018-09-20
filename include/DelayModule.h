#ifndef __DELAY_MODULE_H__
#define __DELAY_MODULE_H__

#include "Module.h"

/// @brief Delay Module
class DelayModule : public Module
{
public:
  DelayModule(std::string name);

  // Process function should return the previous input string
  // ex:
  //    in - "Foo"
  //    out - "hello"
  //    in - "Bar"
  //    out - "Foo"
  virtual std::string process(std::string str);

  // Reset the delay module, so that the next initial output is "hello"
  void reset()
  {
    m_previousStr = "hello";
  }
private:
  std::string m_previousStr = "hello";
};

#endif /* #ifndef __DELAY_MODULE_H__ */
