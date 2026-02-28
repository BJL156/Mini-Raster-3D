#include "output.h"

#include <fstream>
#include <iostream>

void Output::writePPM(Framebuffer &framebuffer, const std::uint32_t width, const std::uint32_t height) {
  std::ofstream file("test.ppm");
  file << "P3\n";
  file << width << ' ' << height << '\n';
  file << "255\n";

  for (std::size_t i = 0; i < width * height; i++) {
    std::uint32_t r = framebuffer.getColorBuffer()[i].x * 255;
    std::uint32_t g = framebuffer.getColorBuffer()[i].y * 255;
    std::uint32_t b = framebuffer.getColorBuffer()[i].z * 255;
    file << r << ' ' << g << ' ' << b << '\n';
  }

  file.close();
}

void Output::writeANSI(Framebuffer &framebuffer, const std::uint32_t width, const std::uint32_t height) {
  for (std::size_t y = 0; y < height; y++) {
    for (std::size_t x = 0; x < width; x++) {
      std::size_t index = y * width + x;
      std::uint32_t r = framebuffer.getColorBuffer()[index].x * 255;
      std::uint32_t g = framebuffer.getColorBuffer()[index].y * 255;
      std::uint32_t b = framebuffer.getColorBuffer()[index].z * 255;
      std::cout << "\033[48;2;" << r << ';' << g << ';' << b << "m \033[0m";
    }
    std::cout << '\n';
  }
}
