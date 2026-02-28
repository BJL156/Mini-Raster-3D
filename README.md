# Mini Raster 3D
A mini 3D rasterization program.

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
