#include "framebuffer.h"

Framebuffer::Framebuffer(const Arguments &arguments)
  : m_width(arguments.getWidth()), m_height(arguments.getHeight()), m_aspectRatio(arguments.getAspectRatio()) {
  m_colorBuffer.resize(m_width * m_height);
  m_depthBuffer.resize(m_width * m_height);
  clear();
}

Framebuffer::~Framebuffer() {

}

void Framebuffer::setPixel(const std::uint32_t x, const std::uint32_t y, const Vec3d &color, const double depth) {
  std::size_t index = y * m_width + x;

  if (depth < m_depthBuffer[index]) {
    m_depthBuffer[index] = depth;
    m_colorBuffer[index] = color;
  }
}

void Framebuffer::clear() {
  for (std::size_t i = 0; i < m_colorBuffer.size(); i++) {
    m_colorBuffer[i] = m_clearColor;
    m_depthBuffer[i] = 1.0;
  }
}

const std::vector<Vec3d> &Framebuffer::getColorBuffer() const {
  return m_colorBuffer;
}
