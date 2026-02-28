#include "utilities.h"

#include <chrono>

Vec3d Utilities::ndcToScreen(const Vec3d &ndc, const std::uint32_t width, const std::uint32_t height) {
  return {
    (1.0 + ndc.x) * 0.5 * width,
    (1.0 - ndc.y) * 0.5 * height,
    ndc.z
  };
}

Vec3d Utilities::getBarycentricCoordinates(const Vec3d &point, const Vec3d &vertex0, const Vec3d &vertex1, const Vec3d &vertex2) {
  Vec3d vec3d0 = vertex1 - vertex0;
  Vec3d vec3d1 = vertex2 - vertex0;
  Vec3d vec3d2 = point - vertex0;

  double d00 = dot(vec3d0, vec3d0);
  double d01 = dot(vec3d0, vec3d1);
  double d11 = dot(vec3d1, vec3d1);
  double d20 = dot(vec3d2, vec3d0);
  double d21 = dot(vec3d2, vec3d1);

  double denom = d00 * d11 - d01 * d01;
  double beta = (d20 * d11 - d21 * d01) / denom;
  double gamma = (d21 * d00 - d20 * d01) / denom;
  double alpha = 1.0 - beta - gamma;

  return { alpha, beta, gamma };
}

double Utilities::degreesToRadians(const double degrees) {
  return degrees * 3.14159 / 180.0;
}

double Utilities::getDeltaTime() {
  static auto previousFrameTime = std::chrono::high_resolution_clock::now();
  auto currentFrameTime = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> duration = currentFrameTime - previousFrameTime;
  double deltaTime = duration.count();

  previousFrameTime = currentFrameTime;

  return deltaTime;
}
