#include "vec3d.h"

#include <cmath>

Vec4d::Vec4d()
  : x(0.0), y(0.0), z(0.0) {

}

Vec4d::Vec4d(double x)
  : x(x), y(x), z(x), w(x) {

}

Vec4d::Vec4d(double x, double y, double z, double w)
  : x(x), y(y), z(z), w(w) {

}

Vec3d::Vec3d() : x(0.0), y(0.0), z(0.0) {

}

Vec3d::Vec3d(double x) : x(x), y(x), z(x) {

}

Vec3d::Vec3d(double x, double y, double z)
  : x(x), y(y), z(z) {

}

Vec3d::Vec3d(const Vec4d &vec4d0)
  : x(vec4d0.x), y(vec4d0.y), z(vec4d0.z) {
}

Vec3d operator+(const Vec3d &vec3d0, const Vec3d &vec3d1) {
  return { vec3d0.x + vec3d1.x, vec3d0.y + vec3d1.y, vec3d0.z + vec3d1.z };
}

Vec3d operator-(const Vec3d &vec3d0, const Vec3d &vec3d1) {
  return { vec3d0.x - vec3d1.x, vec3d0.y - vec3d1.y, vec3d0.z - vec3d1.z };
}

Vec3d operator*(const Vec3d &vec3d0, const Vec3d &vec3d1) {
  return { vec3d0.x * vec3d1.x, vec3d0.y * vec3d1.y, vec3d0.z * vec3d1.z };
}

Vec3d operator/(const Vec3d &vec3d0, const Vec3d &vec3d1) {
  return { vec3d0.x / vec3d1.x, vec3d0.y / vec3d1.y, vec3d0.z / vec3d1.z };
}

Vec3d operator+(double val, const Vec3d &vec3d0) {
  return { val + vec3d0.x, val + vec3d0.y, val + vec3d0.z };
}

Vec3d operator-(double val, const Vec3d &vec3d0) {
  return { val - vec3d0.x, val - vec3d0.y, val - vec3d0.z };
}

Vec3d operator*(double val, const Vec3d &vec3d0) {
  return { val * vec3d0.x, val * vec3d0.y, val * vec3d0.z };
}

Vec3d operator/(double val, const Vec3d &vec3d0) {
  return { val / vec3d0.x, val / vec3d0.y, val / vec3d0.z };
}

Vec3d operator+(const Vec3d &vec3d0, double val) {
  return { vec3d0.x + val, vec3d0.y + val, vec3d0.z + val };
}

Vec3d operator-(const Vec3d &vec3d0, double val) {
  return { vec3d0.x - val, vec3d0.y - val, vec3d0.z - val };
}

Vec3d operator*(const Vec3d &vec3d0, double val) {
  return { vec3d0.x * val, vec3d0.y * val, vec3d0.z * val };
}

Vec3d operator/(const Vec3d &vec3d0, double val) {
  return { vec3d0.x / val, vec3d0.y / val, vec3d0.z / val };
}

Vec3d operator-(const Vec3d &vec3d0) {
  return { -vec3d0.x, -vec3d0.y, -vec3d0.z };
}

double dot(const Vec3d &vec3d0, const Vec3d &vec3d1) {
  return vec3d0.x * vec3d1.x + vec3d0.y * vec3d1.y + vec3d0.z * vec3d1.z;
}

double lengthSquared(const Vec3d &vec3d0) {
  return vec3d0.x * vec3d0.x + vec3d0.y * vec3d0.y + vec3d0.z * vec3d0.z;
}

double length(const Vec3d &vec3d0) {
  return std::sqrt(lengthSquared(vec3d0));
}

Vec3d normalize(const Vec3d &vec3d0) {
  double len = length(vec3d0);
  if (len > 0.0) {
    return vec3d0 / len;
  }

  return vec3d0;
}

Vec3d cross(const Vec3d &vec3d0, const Vec3d &vec3d1) {
  return {
    vec3d0.y * vec3d1.z - vec3d0.z * vec3d1.y,
    vec3d0.z * vec3d1.x - vec3d0.x * vec3d1.z,
    vec3d0.x * vec3d1.y - vec3d0.y * vec3d1.x
  };
}
