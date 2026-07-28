<p align="center">
  <img src="https://github.com/user-attachments/assets/4cb06681-29ac-45de-bf3a-04ce5bd82ccd" alt="preview">
</p>

# Mini Raster 3D
[![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux-lightgrey.svg)](https://www.linux.org/)
[![Renderer](https://img.shields.io/badge/renderer-Software-orange.svg)](#Features)

A mini 3D software rendering rasterization program written from scratch. It supports both terminal output via ANSI escape sequences and high-resolution disk outputs using `.ppm` image files.

This 3D rasterizer is a more polished, direct sequel to [BrayJL - A CodeHS Graphics Engine](https://github.com/BJL156/School-Graphics-Engine/). Its main goal was to fix naive implementation 3D rendering by adding perspective-correct interpolation and removing screen flashing during ANSI terminal rendering.

## Build
Clone the repository and change into its directory:
```bash
git clone [https://github.com/BJL156/Mini-Raster-3D](https://github.com/BJL156/Mini-Raster-3D)
cd Mini-Raster-3D
```
Then run the `makefile`:
```bash
make
```
Then the final executable can be ran directly:
```bash
# Linux
./miniRaster

# Windows
.\miniRaster.exe
```

## Usage
./miniRaster [options]
  --ppm             Write framebuffer to disk using a .ppm file for high resolution renders. (DEFAULT=false)
  --ansi            Write framebuffer to terminal with a render loop. (DEFAULT=true)
  --width [pixels]  Change pixel width (automatically updates height). (IF --ansi DEFAULT=64. IF --ppm DEFAULT=1920)
  --aspect [ratio]  Change aspect ratio. (DEFAULT=16:9)

# Features
- [x] Correct 3D Renders.
  - [x] Depth testing.
  - [x] Perspective correct interpolation.
    - [x] Vertex attributes such as color.
  - [x] Multi Mesh and triangle support.
  - [x] Triangle bounding boxes optimization.
  - [x] Back-face culling.
- [x] Delta time.
- [x] Framebuffers.
  - [x] Color Buffer.
  - [x] Depth Buffer.
- [x] Math Data Types.
  - [x] 3D Vectors `Vec3d` and `Vec4d`.
  - [x] 4x4 Matrices.
  - [x] Operator overloads for vectors and matrices.
  - [x] Transforms such as `translate`, `scale`, `rotateX`, `rotateY`, `rotateZ`.
- [x] Output image to user.
  - [x] Write data to disk via a `.ppm`.
  - [x] Write data to terminal using ANSI escape sequences.
- [x] Command-line arguments.
  - [x] `--ppm` - write framebuffer to disk using a `.ppm` file for high resolution renders. (DEFAULT=false)
  - [x] `--ansi` - write framebuffer to terminal with a render loop. (DEFAULT=true)
  - [x] `--width [pixels]` - change pixel width (automatically updates height). (IF `--ansi` DEFAULT=64. IF `--ppm` DEFAULT=1920)
  - [x] `--aspect [width:height]` - change aspect ratio. (DEFAULT=16:9)
