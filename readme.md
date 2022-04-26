# **Vector library in C**
A probably very bad vector library written in C. 
Supports 2-4 dimensional vectors, arbitrarily sized and 4x4 
homogenous matrices, and basic functions for graphics programming.

## version branches
- **master - stable**
  - compiles without warnings
  - supports generic prints and constructors
- **experimental - unstable**
  - compiles with warnings
  - supports variadic object constructors >:)

## quick start
just include the headeronly file in the top level of the repository. the src modules can be manually compiled for testing.

### _header only_
```c
#include "vec.h"
```

### _compile_
```
git clone https://github.com/sjdobesh/vec
cd vec/src
make
```

## use

### _basic use - vectors_
```c
v2 a = new_v2(1.0, 2.5);
v2 b = new_v2(3.0, 1.5);
a = vadd(a, b);
printv(a);
printv(vdot(a, b));
```

### _basic use - matrices_
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
matfree(m); // remember to free matrices you make!
matfree(id);
```

### _generic variadic constructors_
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

## Structures
### _Vectors_
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
### _Matrix_

```c
struct matrix {
  float** m;
  int x, y;
}
```

## functions

### _vectors_
#### allocation

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

### _Matrices_
#### Allocation
```c
matrix matalloc(int, int);        // allocate an arbitrarily sized matrix
void matfree(matrix);             // free a matrix
matrix new_m4(const float[4][4]); // 4x4 homogenous matrix
matrix m4proj(                    // create a projection matrix
  int w, int h,                   //   - width, height
  float fov,                      //   - field of view in degrees
  float znear, float zfar         //   - z clip planes, near and far
); 
matrix m4lookat(                  // create a lookat matrix
  v4 pos,                         // camera position
  v4 target,                      // camera target position
  v4 up                           // relative up vector for camera
);
matrix m4xrot(float r);           // rotation matrices
matrix m4yrot(float r);           // r is in degrees
matrix m4zrot(float r);        
matrix m4trans(                   // translation matrix
  float x, float y, float z    
);                             
matrix m4invxy();                 // invert x and y
matrix m4id();                    // identity matrix
matrix m4empty();                 // empty matrix
```
#### Utility
```c
void printm(matrix);            // print a matrix
int meq(matrix, matrix);        // matrix equal (returns 0 on true)
matrix mcp(matrix);             // make a deep copy of a matrix
v4 mxv(matrix m, v4 v);         // multiply an m4 by a v4
matrix mxm(matrix a, matrix b); // multiply two matrices together
```

### _Misc_
These aren't intended for external use, but they are here if you want em.
```c
float rtod(float rad);          // radian to degrees
float dtor(float deg);          // degrees to radian
float flim(float x, float lim); // float limit
```
