#ifndef OUTPUT_H
#define OUTPUT_H

#include <cstdint>
#include <vector>

#include "framebuffer.h"
#include "vec3d.h"

class Output {
public:
  static void writePPM(Framebuffer &framebuffer, const std::uint32_t width, const std::uint32_t height);
  static void writeANSI(Framebuffer &framebuffer, const std::uint32_t width, const std::uint32_t height);
};

#endif
