#include "application.h"
#include "arguments.h"

int main(int argc, char **argv) {
  Arguments arguments(argc, argv);
  
  Application application(arguments);
  application.run();

  return 0;
}
