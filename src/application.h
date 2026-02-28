#ifndef APPLICATION_H
#define APPLICATION_H

#include "arguments.h"

#include <cstdint>

class Application {
public:
  Application(const Arguments &arguments);
  ~Application();

  void run();
private:
  const Arguments m_arguments;
};

#endif
