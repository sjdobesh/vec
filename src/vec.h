#ifndef _VEC_H_
#define _VEC_H_

typedef unsigned int uint;

// VECTOR STRUCTS

typedef struct v2 {
  float x, y;
} v2;

typedef struct v3 {
  float x, y, z;
} v3;

typedef struct v4 {
  float x, y, z, w;
} v4;

// MATRIX

typedef struct m2 {
  float** m; // the matrix
  uint x, y; // the dimensions
} m2;

typedef struct m3 {
  float*** m;    // the matrix
  uint x, y, z; // the dimensions
} m3;

typedef struct m4 {
  float**** m;      // the matrix
  uint x, y, z, w; // the dimensions
} m4;

// GENERIC FUNCTIONS

#define vadd(a, b) _Generic ((a) v2: v2add, v3: v3add, v4: v4add) (a,b)
v2 v2add(v2 a, v2 b);
v3 v3add(v3 a, v3 b);
v4 v4add(v4 a, v4 b);

#define vsub(a, b) _Generic ((a) v2: v2sub, v3: v3sub, v4: v4sub) (a,b)
v2 v2sub(v2 a, v2 b);
v3 v3sub(v3 a, v3 b);
v4 v4sub(v4 a, v4 b);

#define vmul(a, b) _Generic ((a) v2: v2mul, v3: v3mul, v4: v4mul) (a,b)
v2 v2mul(v2 a, v2 b);
v3 v3mul(v3 a, v3 b);
v4 v4mul(v4 a, v4 b);

#define vdiv(a, b) _Generic ((a) v2: v2div, v3: v3div, v4: v4div) (a,b)
v2 v2div(v2 a, v2 b);
v3 v3div(v3 a, v3 b);
v4 v4div(v4 a, v4 b);

#define vlim(a, b) _Generic ((a) v2: v2lim, v3: v3lim, v4: v4lim) (a,b)
v2 v2lim(v2 a, v2 b);
v3 v3lim(v3 a, v3 b);
v4 v4lim(v4 a, v4 b);

#define vmag(a, b) _Generic ((a) v2: v2mag, v3: v3mag, v4: v4mag) (a,b)
v2 v2mag(v2 a, v2 b);
v3 v3mag(v3 a, v3 b);
v4 v4mag(v4 a, v4 b);

#define vscl(a, b) _Generic ((a) v2: v2scl, v3: v3scl, v4: v4scl) (a,b)
v2 v2scl(v2 a, v2 b);
v3 v3scl(v3 a, v3 b);
v4 v4scl(v4 a, v4 b);

// math util prototypes
float rad2deg(float rad);
float deg2rad(float deg);
float flim(float x, float lim);

#endif
