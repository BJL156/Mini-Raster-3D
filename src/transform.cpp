#include "transform.h"

#include "utilities.h"

#include <cmath>

Mat4d Transform::translate(const Vec3d &vec3d0) {
  Mat4d result{ 1.0 };

  result[0][3] = vec3d0.x;
  result[1][3] = vec3d0.y;
  result[2][3] = vec3d0.z;

  return result;
}

Mat4d Transform::scale(const Vec3d &vec3d0) {
  Mat4d result{ 1.0 };

  result[0][0] = vec3d0.x;
  result[1][1] = vec3d0.y;
  result[2][2] = vec3d0.z;

  return result;
}

Mat4d Transform::rotateX(const double radians) {
  Mat4d result{ 1.0 };

  const double cosRadians = std::cos(radians);
  const double sinRadians = std::sin(radians);

  result[1][1] = cosRadians;
  result[2][1] = -sinRadians;
  result[1][2] = sinRadians;
  result[2][2] = cosRadians;

  return result;
}

Mat4d Transform::rotateY(const double radians) {
  Mat4d result{ 1.0 };

  const double cosRadians = std::cos(radians);
  const double sinRadians = std::sin(radians);

  result[0][0] = cosRadians;
  result[0][2] = -sinRadians;
  result[2][0] = sinRadians;
  result[2][2] = cosRadians;

  return result;
}

Mat4d Transform::rotateZ(const double radians) {
  Mat4d result{ 1.0 };

  const double cosRadians = std::cos(radians);
  const double sinRadians = std::sin(radians);

  result[0][0] = cosRadians;
  result[0][1] = -sinRadians;
  result[1][0] = sinRadians;
  result[1][1] = cosRadians;

  return result;
}

Mat4d Transform::getModelMatrix(const Vec3d &position, const Vec3d &rotation, const Vec3d &dilation) {
  return translate(position) * rotateY(Utilities::degreesToRadians(rotation.y)) * rotateX(Utilities::degreesToRadians(rotation.x)) * rotateZ(Utilities::degreesToRadians(rotation.z)) * scale(dilation);
}

Mat4d Transform::perspective(double fov, double aspectRatio, double near, double far) {
  Mat4d result{ 1.0 };

  double tanHalfFOV = std::tan(fov / 2.0);
  result[0][0] = 1.0 / (aspectRatio * tanHalfFOV);
  result[1][1] = 1.0 / tanHalfFOV;
  result[2][2] = -(far + near) / (far - near);
  result[2][3] = -(2.0 * far * near) / (far - near);
  result[3][2] = -1.0;
  result[3][3] = 0.0;

  return result;
}
