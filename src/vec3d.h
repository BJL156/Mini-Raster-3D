#ifndef VEC3D_H
#define VEC3D_H

struct Vec4d {
  Vec4d();
  Vec4d(double x);
  Vec4d(double x, double y, double z, double w);

  double x;
  double y;
  double z;
  double w;
};

struct Vec3d {
  Vec3d();
  Vec3d(double x);
  Vec3d(double x, double y, double z);
  Vec3d(const Vec4d &vec4d0);

  double x;
  double y;
  double z;
};

struct Vec2i {
  int x;
  int y;
};

Vec3d operator+(const Vec3d &vec3d0, const Vec3d &vec3d1);
Vec3d operator-(const Vec3d &vec3d0, const Vec3d &vec3d1);
Vec3d operator*(const Vec3d &vec3d0, const Vec3d &vec3d1);
Vec3d operator/(const Vec3d &vec3d0, const Vec3d &vec3d1);

Vec3d operator+(double val, const Vec3d &vec3d0);
Vec3d operator-(double val, const Vec3d &vec3d0);
Vec3d operator*(double val, const Vec3d &vec3d0);
Vec3d operator/(double val, const Vec3d &vec3d0);

Vec3d operator+(const Vec3d &vec3d0, double val);
Vec3d operator-(const Vec3d &vec3d0, double val);
Vec3d operator*(const Vec3d &vec3d0, double val);
Vec3d operator/(const Vec3d &vec3d0, double val);

Vec3d operator-(const Vec3d &vec3d0);

double dot(const Vec3d &vec3d0, const Vec3d &vec3d1);
double lengthSquared(const Vec3d &vec3d0);
double length(const Vec3d &vec3d0);
Vec3d normalize(const Vec3d &vec3d0);
Vec3d cross(const Vec3d &vec3d0, const Vec3d &vec3d1);

#endif
