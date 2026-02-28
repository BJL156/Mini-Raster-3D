#ifndef UTILITIES_H
#define UTILITIES_H

#include "vec3d.h"

#include <cstdint>

class Utilities {
public:
  static Vec3d ndcToScreen(const Vec3d &ndc, const std::uint32_t width, const std::uint32_t height);
  static Vec3d getBarycentricCoordinates(const Vec3d &point, const Vec3d &vertex0, const Vec3d &vertex1, const Vec3d &vertex2);
  static double degreesToRadians(const double degrees);

  static double getDeltaTime();
};

#endif
