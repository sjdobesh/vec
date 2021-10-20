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


// a matrix is just a float** with dimensions
typedef struct matrix {
  float** m;
  int x, y;
} matrix;


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

#define vlim(a, s) _Generic ((a) v2: v2lim, v3: v3lim, v4: v4lim) (a,s)
v2 v2lim(v2 a, float s);
v3 v3lim(v3 a, float s);
v4 v4lim(v4 a, float s);

#define vmag(v) _Generic ((v) v2: v2mag, v3: v3mag, v4: v4mag) (v)
float v3mag(v3 v);
float v2mag(v2 v);
float v4mag(v4 v);

#define vscl(a, s) _Generic ((a) v2: v2scl, v3: v3scl, v4: v4scl) (a,s)
v2 v2scl(v2 a, float s);
v3 v3scl(v3 a, float s);
v4 v4scl(v4 a, float s);

// vector util functions

v2 newv2(float x, float y);
v3 newv3(float x, float y, float z);
v4 newv4(float x, float y, float z, float w);

// vec to ptr
#define vtop(v) _Generic ((v) v2: v2top, v3: v3top, v4: v4top) (v)
float* v2top(v2 v);
float* v3top(v3 v);
float* v4top(v4 v);

// ptr to vec
v2 ptov2(float* p);
v3 ptov3(float* p);
v4 ptov4(float* p);

// matrix util functions

// alloc & free

// float table
float* fpalloc(int x);
float** ftalloc(int x, int y);
void ftfree(float** ft, int x);

// matrix struct
matrix matalloc(int x, int y);
void matfree(matrix m);

// math util prototypes
float rad2deg(float rad);
float deg2rad(float deg);
float flim(float x, float lim);

// printing functions
#define printv(v) _Generic ((v), v2: printv2, v3: printv3, v4: printv4) (v)
void printv2(v2 v);
void printv3(v3 v);
void printv4(v4 v);

#endif
