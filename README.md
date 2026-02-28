<p align="center">
  <img src="https://github.com/user-attachments/assets/4cb06681-29ac-45de-bf3a-04ce5bd82ccd" alt="preview">
</p>

# Mini Raster 3D
A mini 3D software rendering rasterization program.

# About
This program is a more polished direct sequel to [BrayJL - A CodeHS Graphics Engine](https://github.com/BJL156/School-Graphics-Engine/). It's main goal was to fix the incorrect and naive 3D implementation specifically by adding:
- Perspective correct interpolation.
- Fix screen flashing with ANSI rendering.

Both of which are fixed in this new version along with new command line arguments so the code doesn't need to be recompiled every time the output of the render needs to change such as width, aspect ratio, and if it's being rendered to the disk or to the terminal.

# Features
- [x] Correct 3D Renders.
  - [x] Depth testing.
  - [x] Perspective correct interpolation.
    - [x] Vertex attributes such as color.
  - [x] Multi Mesh and triangle support.
  - [x] Triangle bounding boxes optimization.
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

# Build
1. Clone the repository and change into it's directory:
```
git clone https:BJL156/Mini-Raster-3D
cd Mini-Raster-3D
```
2. Run the `makefile` (works in either Windows or Linux):
```
make
```
3. Run program:
```
./miniRaster
```
Or Windows:
```
.\miniRaster.exe
```
