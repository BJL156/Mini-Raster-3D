#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "arguments.h"
#include "vec3d.h"

#include <cstdint>
#include <vector>

class Framebuffer {
public:
  Framebuffer(const Arguments &arguments);
  ~Framebuffer();

  void setPixel(const std::uint32_t x, const std::uint32_t y, const Vec3d &color, const double depth);
  void clear();

  const std::vector<Vec3d> &getColorBuffer() const;
private:
  const std::uint32_t m_width;
  const std::uint32_t m_height;
  const double m_aspectRatio;

  Vec3d m_clearColor = { 0.1, 0.1, 0.1 };

  std::vector<Vec3d> m_colorBuffer;
  std::vector<double> m_depthBuffer;
};

#endif
