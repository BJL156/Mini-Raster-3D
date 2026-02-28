#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <cstdint>

class Arguments {
public:
  Arguments(int argc, char **argv);
  ~Arguments();

  bool getIsOutputANSI() const;
  double getAspectRatio() const;
  std::uint32_t getWidth() const;
  std::uint32_t getHeight() const;
private:
  void handleArgs(int argc, char **argv);

  bool m_isOutputANSI = true;
  double m_aspectRatio = 16.0 / 9.0;
  std::uint32_t m_width = 0;
  std::uint32_t m_height = 0;
};

#endif
