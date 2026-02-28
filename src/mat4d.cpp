#include "mat4d.h"

Mat4d::Mat4d(double x) {
  for (std::size_t i = 0; i < 4; i++) {
    for (std::size_t j = 0; j < 4; j++) {
      data[i][j] = (i == j) ? x : 0.0;
    }
  }
}

Mat4d::~Mat4d() {

}

double *Mat4d::operator[](std::size_t i) {
  return data[i];
}

const double *Mat4d::operator[](std::size_t i) const {
  return data[i];
}

Mat4d operator*(const Mat4d &mat4d0, const Mat4d &mat4d1) {
  Mat4d result{ 1.0 };

  for (std::size_t i = 0; i < 4; i++) {
    for (std::size_t j = 0; j < 4; j++) {
      result[i][j] = 0.0;

      for (size_t k = 0; k < 4; k++) {
        result[i][j] += mat4d0[i][k] * mat4d1[k][j];
      }
    }
  }

  return result;
}

Vec4d operator*(const Mat4d &mat4d0, const Vec4d &vec4d0) {
  Vec4d result;

  result.x = mat4d0[0][0] * vec4d0.x + mat4d0[0][1] * vec4d0.y + mat4d0[0][2] * vec4d0.z + mat4d0[0][3] * vec4d0.w;
  result.y = mat4d0[1][0] * vec4d0.x + mat4d0[1][1] * vec4d0.y + mat4d0[1][2] * vec4d0.z + mat4d0[1][3] * vec4d0.w;
  result.z = mat4d0[2][0] * vec4d0.x + mat4d0[2][1] * vec4d0.y + mat4d0[2][2] * vec4d0.z + mat4d0[2][3] * vec4d0.w;
  result.w = mat4d0[3][0] * vec4d0.x + mat4d0[3][1] * vec4d0.y + mat4d0[3][2] * vec4d0.z + mat4d0[3][3] * vec4d0.w;

  return result;
}
