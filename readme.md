# Vector library in C
A probably very bad vector library written in C. Supports 2-4 dimensional vectors, arbitrarily sized and 4x4 homogenous matrices, and basic functions for graphics programming.

## Quick Start
Just include the headeronly file in the top level of the repository. The src modules can be manually compiled for testing.

**Note:** this won't compile cleanly with `-Wall`, but it's fine, just use everything like you're supposed to and its fine, i swear... :)

### Header Only
```c
#include "vec.h"
```

### Compile
```
git clone https://github.com/sjdobesh/vec
cd vec/src
make
```
## Use

### Basic Use Example - Vectors
```c
v2 a = new_v2(1.0, 2.5);
v2 b = new_v2(3.0, 1.5);
a = vadd(a, b);
printv(a);
printv(vdot(a, b));
```

### Generic Variadic Constructors
```c
// v2
v2 a = new_v2(1.0, 2.0);
// v3
v3 b = new_v3(1.0, 2.0, 3.0);
v3 c = new_v3(a, 3.0);
// v4
v4 d = new_v4(1.0, 2.0, 3.0, 4.0);
v4 e = new_v4(a, 3.0, 4.0);
v4 f = new_v4(b, 4.0);
v4 g = new_v4(a, a);
// generic prints
printv(a);
printv(b);
printv(d);
```

### Matrices
```c
const float vals[4][4] = {
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1}
}
matrix m = new_m4(vals);
int val = m.m[0][0];
printm(m);
matrix id = id_mat();
meq(m, id) ? printf("equal\n") : printf("unequal\n");
matfree(m);
matfree(id);
```

## Structures
### Vectors
```c
struct v2 {
  float x, y;
};
struct v3 {
  float x, y, z;
};
struct v4 {
  float x, y, z, w;
};
```
### Matrix
```c
struct matrix {
  float** m;
  int x, y;
}
```

## Functions

### Vectors
#### Allocation
```c
// 2D vector
v2 new_v2(float, float);
// 3D vector
v3 new_v3(float, float, float);
v3 new_v3(v2, float);
// 4D vector
v4 new_v4(float, float, float, float);
v4 new_v4(v2, float, float);
v4 new_v4(v3, float);
v4 new_v4(v2, v2);
```
#### Vector Math
```c
vX vadd(vX, vX);       // element-wise addition
vX vsub(vX, vX);       // element-wise subtraction
vX vmul(vX, vX);       // element-wise multiplication
vX vdiv(vX, vX);       // element-wise division
vX vlim(vX, float);    // limit vector magnitude
vX vscl(vX, float);    // vector scale
float vdot(vX, vX);    // vector dot product
float vmag(vX, float); // vector magnitude
vX vnorm(vX);          // normalize
vX vcross(vX, vX);     // cross product
```
#### Utility
```c
void printv(vX);  // print vector
int veq(vX, vX);  // vector equal (returns 0 on true)
float* vtop(vX);  // convert a vector to a float pointer
v2 ptov2(float*); // convert a float pointer to a vector
v3 ptov3(float*);
v4 ptov4(float*);
```

### Matrices
#### Allocation
```c
matrix matalloc(int, int);        // allocate an arbitrarily sized matrix
void matfree(matrix);             // free a matrix
matrix new_m4(const float[4][4]); // 4x4 homogenous matrix
matrix proj_mat(                  // create a projection matrix
  int w, int h,                   // width, height
  float fov,                      // field of view in degrees
  float znear, float zfar         // z clip planes, near and far
); 
matrix xrot_mat(float r);         // rotation matrices
matrix yrot_mat(float r);         // r is in degrees
matrix zrot_mat(float r);
matrix trans_mat(                 // translation matrix
  float x, float y, float z
);
matrix invxy_mat();               // invert x and y
matrix id_mat();                  // identity matrix
matrix empty_mat();               // empty matrix
```
#### Utility
```c
void printm(matrix);     // print a matrix
int meq(matrix, matrix); // matrix equal (returns 0 on true)
matrix mcp(matrix);      // make a deep copy of a matrix
```
