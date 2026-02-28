#include "application.h"

#include "framebuffer.h"
#include "mat4d.h"
#include "output.h"
#include "transform.h"
#include "utilities.h"
#include "vec3d.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct VertexInput {
  Vec3d position;
  Vec3d color;
};

struct VertexOutput {
  Vec4d clipPosition;
  Vec3d color;
  double inverseW;
};

VertexOutput vertexShader(const VertexInput &in, const Mat4d &mvp) {
  VertexOutput out;

  Vec4d clip = mvp * Vec4d(in.position.x, in.position.y, in.position.z, 1.0);

  out.clipPosition = clip;
  out.inverseW = 1 / clip.w;
  out.color = in.color;

  return out;
}

struct FragmentInput {
  Vec3d color;
};

Vec3d fragmentShader(const FragmentInput &in) {
  return in.color;
}

struct Mesh {
  std::vector<VertexInput> vertices;
  Vec3d position = { 0.0, 0.0, 0.0 };
  Vec3d rotation = { 0.0, 0.0, 0.0 };
  Vec3d dilation = { 1.0, 1.0, 1.0 };
};

void rasterizeTriangle(const VertexOutput vertices[3], Framebuffer &framebuffer, const std::uint32_t width, const std::uint32_t height) {
  Vec3d screen[3];
  for (std::size_t i = 0; i < 3; i++) {
    Vec3d ndc{
      vertices[i].clipPosition.x * vertices[i].inverseW,
      vertices[i].clipPosition.y * vertices[i].inverseW,
      vertices[i].clipPosition.z * vertices[i].inverseW
    };

    screen[i] = Utilities::ndcToScreen(ndc, width, height);
  }

  double area =
    (screen[1].x - screen[0].x) * (screen[2].y - screen[0].y) -
    (screen[1].y - screen[0].y) * (screen[2].x -screen[0].x);
  if (area >= 0.0) {
    return;
  }

  int minX = std::max(0, (int)std::floor(std::min({screen[0].x, screen[1].x, screen[2].x})));
  int maxX = std::min((int)width - 1, (int)std::ceil(std::max({screen[0].x, screen[1].x, screen[2].x})));
  int minY = std::max(0, (int)std::floor(std::min({screen[0].y, screen[1].y, screen[2].y})));
  int maxY = std::min((int)height - 1, (int)std::ceil(std::max({screen[0].y, screen[1].y, screen[2].y})));

  for (int y = minY; y <= maxY; y++) {
    for (int x = minX; x <= maxX; x++) {
      Vec3d point = {
        static_cast<double>(x),
        static_cast<double>(y),
        0.0
      };

      const double epsilon = 1.0e-5;
      Vec3d bary = Utilities::getBarycentricCoordinates(point, screen[0], screen[1], screen[2]);
      if (bary.x >= -epsilon && bary.y >= -epsilon && bary.z >= -epsilon) {
        double interpolatedInverseW =
          bary.x * vertices[0].inverseW +
          bary.y * vertices[1].inverseW +
          bary.z * vertices[2].inverseW;

        double z =
          vertices[0].clipPosition.z * (bary.x * vertices[0].inverseW) +
          vertices[1].clipPosition.z * (bary.y * vertices[1].inverseW) +
          vertices[2].clipPosition.z * (bary.z * vertices[2].inverseW);
        z = (z + 1.0) * 0.5;

        Vec3d interpolatedColor =
          vertices[0].color * (bary.x * vertices[0].inverseW) +
          vertices[1].color * (bary.y * vertices[1].inverseW) +
          vertices[2].color * (bary.z * vertices[2].inverseW); 
        interpolatedColor = {
          interpolatedColor.x / interpolatedInverseW,
          interpolatedColor.y / interpolatedInverseW,
          interpolatedColor.z / interpolatedInverseW
        };

        FragmentInput fragmentInput;
        fragmentInput.color = interpolatedColor;
        Vec3d finalColor = fragmentShader(fragmentInput);

        framebuffer.setPixel(x, y, finalColor, z);
      }
    }
  }
}

void render(Framebuffer &framebuffer, const std::vector<Mesh> &scene, const std::uint32_t width, const std::uint32_t height, const double aspectRatio) {
  framebuffer.clear();

  Mat4d proj = Transform::perspective(Utilities::degreesToRadians(60.0), aspectRatio, 0.01, 100.0);

  for (const Mesh &mesh : scene) {
    Mat4d model = Transform::getModelMatrix(mesh.position, mesh.rotation, mesh.dilation);
    Mat4d mvp = proj * model;

    std::vector<VertexOutput> vertices;
    for (const VertexInput &vertexInput: mesh.vertices) {
      vertices.push_back(vertexShader(vertexInput, mvp));
    }

    for (std::size_t i = 0; i + 2 < vertices.size(); i += 3) {
      if (vertices[i].clipPosition.w >= 0.0 && vertices[i + 1].clipPosition.w >= 0.0 && vertices[i + 2].clipPosition.w >= 0.0) {
        rasterizeTriangle(&vertices[i], framebuffer, width, height);
      }
    }
  }
}

Application::Application(const Arguments &arguments)
  : m_arguments(arguments) {

}

Application::~Application() {

}

void Application::run() {
  const std::uint32_t width = m_arguments.getWidth();
  const std::uint32_t height = m_arguments.getHeight();

  Framebuffer framebuffer(m_arguments);

  std::vector<Mesh> scene;

  {
    Mesh mesh;
    mesh.vertices = {
      { { -0.5, -0.5, -0.5 }, { 1.0, 0.0, 0.0 } }, { { -0.5,  0.5, -0.5 }, { 1.0, 0.0, 0.0 } }, { {  0.5,  0.5, -0.5 }, { 1.0, 0.0, 0.0 } },
      { {  0.5,  0.5, -0.5 }, { 1.0, 0.0, 0.0 } }, { {  0.5, -0.5, -0.5 }, { 1.0, 0.0, 0.0 } }, { { -0.5, -0.5, -0.5 }, { 1.0, 0.0, 0.0 } },

      { { -0.5, -0.5,  0.5 }, { 0.0, 1.0, 0.0 } }, { {  0.5, -0.5,  0.5 }, { 0.0, 1.0, 0.0 } }, { {  0.5,  0.5,  0.5 }, { 0.0, 1.0, 0.0 } },
      { {  0.5,  0.5,  0.5 }, { 0.0, 1.0, 0.0 } }, { { -0.5,  0.5,  0.5 }, { 0.0, 1.0, 0.0 } }, { { -0.5, -0.5,  0.5 }, { 0.0, 1.0, 0.0 } },

      { { -0.5, -0.5, -0.5 }, { 0.0, 0.0, 1.0 } }, { { -0.5, -0.5,  0.5 }, { 0.0, 0.0, 1.0 } }, { { -0.5,  0.5,  0.5 }, { 0.0, 0.0, 1.0 } },
      { { -0.5,  0.5,  0.5 }, { 0.0, 0.0, 1.0 } }, { { -0.5,  0.5, -0.5 }, { 0.0, 0.0, 1.0 } }, { { -0.5, -0.5, -0.5 }, { 0.0, 0.0, 1.0 } },

      { {  0.5, -0.5, -0.5 }, { 1.0, 1.0, 0.0 } }, { {  0.5,  0.5, -0.5 }, { 1.0, 1.0, 0.0 } }, { {  0.5,  0.5,  0.5 }, { 1.0, 1.0, 0.0 } },
      { {  0.5,  0.5,  0.5 }, { 1.0, 1.0, 0.0 } }, { {  0.5, -0.5,  0.5 }, { 1.0, 1.0, 0.0 } }, { {  0.5, -0.5, -0.5 }, { 1.0, 1.0, 0.0 } },

      { { -0.5, -0.5, -0.5 }, { 1.0, 0.0, 1.0 } }, { {  0.5, -0.5, -0.5 }, { 1.0, 0.0, 1.0 } }, { {  0.5, -0.5,  0.5 }, { 1.0, 0.0, 1.0 } },
      { {  0.5, -0.5,  0.5 }, { 1.0, 0.0, 1.0 } }, { { -0.5, -0.5,  0.5 }, { 1.0, 0.0, 1.0 } }, { { -0.5, -0.5, -0.5 }, { 1.0, 0.0, 1.0 } },

      { { -0.5,  0.5, -0.5 }, { 0.0, 1.0, 1.0 } }, { { -0.5,  0.5,  0.5 }, { 0.0, 1.0, 1.0 } }, { {  0.5,  0.5,  0.5 }, { 0.0, 1.0, 1.0 } },
      { {  0.5,  0.5,  0.5 }, { 0.0, 1.0, 1.0 } }, { {  0.5,  0.5, -0.5 }, { 0.0, 1.0, 1.0 } }, { { -0.5,  0.5, -0.5 }, { 0.0, 1.0, 1.0 } },
    };
    mesh.position = { 0.0, 0.0, -2.0 };
    mesh.rotation = { 0.0, 0.0, 0.0 };
    mesh.dilation = { 1.0, 1.0, 1.0 };
    scene.push_back(mesh);
  }

  if (m_arguments.getIsOutputANSI()) {
    std::cout << "\033[2J";
    while (true) {
      std::cout << "\033[1;1H";

      double deltaTime = Utilities::getDeltaTime();
      scene[0].rotation.x += 60.0 * deltaTime;
      scene[0].rotation.y += 45.0 * deltaTime;

      render(framebuffer, scene, width, height, m_arguments.getAspectRatio());
      Output::writeANSI(framebuffer, width, height);
    }
  } else {
    render(framebuffer, scene, width, height, m_arguments.getAspectRatio());
    Output::writePPM(framebuffer, width, height);
  }
}
