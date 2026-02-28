#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "mat4d.h"
#include "vec3d.h"

class Transform {
public:
  static Mat4d translate(const Vec3d &vec3d0);
  static Mat4d scale(const Vec3d &vec3d0);
  static Mat4d rotateX(const double radians);
  static Mat4d rotateY(const double radians);
  static Mat4d rotateZ(const double radians);
  static Mat4d getModelMatrix(const Vec3d &position, const Vec3d &rotation, const Vec3d &dilation);

  static Mat4d perspective(double fov, double aspectRatio, double near, double far);
};

#endif
