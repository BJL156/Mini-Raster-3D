#ifndef MAT4_H
#define MAT4_H

#include "vec3d.h"

#include <cstddef>

struct Mat4d {
  Mat4d(double x);
  ~Mat4d();

  double *operator[](std::size_t i);
  const double *operator[](std::size_t i) const;

  double data[4][4];
};

Mat4d operator*(const Mat4d &mat4d0, const Mat4d &mat4d1);
Vec4d operator*(const Mat4d &mat4d0, const Vec4d &vec4d0);

#endif
