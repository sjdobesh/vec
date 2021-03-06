h/ std
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

// custom
#include "vec.h"

#define PI 3.1415926535

/*---- VECTOR FUNCTIONS ----*/

// vector addition
v2 v2add(v2 a, v2 b){
  a.x = a.x + b.x;
  a.y = a.y + b.y;
  return a;
}
v3 v3add(v3 a, v3 b){
  a.x = a.x + b.x;
  a.y = a.y + b.y;
  a.z = a.z + b.z;
  return a;
}
v4 v4add(v4 a, v4 b){
  a.x = a.x + b.x;
  a.y = a.y + b.y;
  a.z = a.z + b.z;
  a.w = a.w + b.w;
  return a;
}

// vector substract
v2 v2sub(v2 a, v2 b){
  a.x = a.x - b.x;
  a.y = a.y - b.y;
  return a;
}
v3 v3sub(v3 a, v3 b){
  a.x = a.x - b.x;
  a.y = a.y - b.y;
  a.z = a.z - b.z;
  return a;
}
v4 v4sub(v4 a, v4 b){
  a.x = a.x - b.x;
  a.y = a.y - b.y;
  a.z = a.z - b.z;
  a.w = a.w - b.w;
  return a;
}

// vector multiply
v2 v2mul(v2 a, v2 b){
  a.x = a.x * b.x;
  a.y = a.y * b.y;
  return a;
}
v3 v3mul(v3 a, v3 b){
  a.x = a.x * b.x;
  a.y = a.y * b.y;
  a.z = a.z * b.z;
  return a;
}
v4 v4mul(v4 a, v4 b){
  a.x = a.x * b.x;
  a.y = a.y * b.y;
  a.z = a.z * b.z;
  a.w = a.w * b.w;
  return a;
}

// vector division
v2 v2div(v2 a, v2 b){
  a.x = a.x / b.x;
  a.y = a.y / b.y;
  return a;
}
v3 v3div(v3 a, v3 b){
  a.x = a.x / b.x;
  a.y = a.y / b.y;
  a.z = a.z / b.z;
  return a;
}
v4 v4div(v4 a, v4 b){
  a.x = a.x / b.x;
  a.y = a.y / b.y;
  a.z = a.z / b.z;
  a.w = a.w / b.w;
  return a;
}

// vector limit
v2 v2lim(v2 v, float s){
  v.x = flim(v.x, s);
  v.y = flim(v.y, s);
  return v;
}
v3 v3lim(v3 v, float s){
  v.x = flim(v.x, s);
  v.y = flim(v.y, s);
  v.z = flim(v.z, s);
  return v;
}
v4 v4lim(v4 v, float s){
  v.x = flim(v.x, s);
  v.y = flim(v.y, s);
  v.z = flim(v.z, s);
  v.w = flim(v.w, s);
  return v;
}

// magnitude function
float v2mag(v2 v){
  return sqrt(pow(v.x, 2) + pow(v.y, 2));
}
float v3mag(v3 v){
  return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}
float v4mag(v4 v){
  return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2) + pow(v.w, 2));
}

// vector scale
v2 v2scl(v2 v, float s){
  v.x = v.x * s;
  v.y = v.y * s;
  return v;
}
v3 v3scl(v3 v, float s){
  v.x = v.x * s;
  v.y = v.y * s;
  v.z = v.z * s;
  return v;
}
v4 v4scl(v4 v, float s){
  v.x = v.x * s;
  v.y = v.y * s;
  v.z = v.z * s;
  v.w = v.w * s;
  return v;
}

// vector dot product
float v2dot(v2 a, v2 b){
  return (
    (a.x * b.x) +
    (a.y * b.y)
  );
}
float v3dot(v3 a, v3 b){
  return (
    (a.x * b.x) +
    (a.y * b.y) +
    (a.z * b.z)
  );
}
float v4dot(v4 a, v4 b){
  return (
    (a.x * b.x) +
    (a.y * b.y) +
    (a.z * b.z) +
    (a.w * b.w)
  );
}

// vector normalize
v2 v2norm(v2 v){
  float len = vmag(v);
  v.x = v.x / len;
  v.y = v.y / len;
  return v;
}
v3 v3norm(v3 v){
  float len = vmag(v);
  v.x = v.x / len;
  v.y = v.y / len;
  v.z = v.z / len;
  return v;
}
v4 v4norm(v4 v){
  float len = vmag(v);
  v.x = v.x / len;
  v.y = v.y / len;
  v.z = v.z / len;
  v.w = v.w / len;
  return v;
}

// vector cross product
v2 v2cross(v2 a, v2 b){
  return a;
}
v3 v3cross(v3 a, v3 b){
  return a;
}
v4 v4cross(v4 a, v4 b){
  return a;
}


/*---- NEW STRUCT FUNCTIONS ----*/

// vector packing functions
// v2
v2 new_v2_f(float x, float y) {
  v2 vec = {x, y};
  return vec;
}
// v3
v3 new_v3_f(float x, ...) {
  va_list args;
  va_start(args, 2);
  v3 vec = {x, va_arg(args, double), va_arg(args, double)};
  va_end(args);
  return vec;
}
v3 new_v3_v2(v2 v, ...) {
  va_list args;
  va_start(args, 1);
  v3 vec = {v.x, v.y, va_arg(args, double)};
  va_end(args);
  return vec;
}
// v4
v4 new_v4_f(float x, float y, ...) {
  va_list args;
  va_start(args, 2);
  v4 vec = {
    x,
    y,
    va_arg(args, double),
    va_arg(args, double)};
  va_end(args);
  return vec;
}
v4 new_v4_v2(v2 v, float z, ...) {
  va_list args;
  va_start(args, 1);
  v4 vec = {v.x, v.y, z, va_arg(args, double)};
  va_end(args);
  return vec;
}
v4 new_v4_v2v2(v2 a, v2 b) {
  v4 vec = {a.x, a.y, b.x, b.y};
  return vec;
}
v4 new_v4_v3(v3 v, float w) {
  v4 vec = {v.x, v.y, v.z, w};
  return vec;
}



// allocate and populat a 4x4 homogenous matrix
matrix new_m4(const float vals[4][4]) {
  matrix m = matalloc(4, 4);
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      m.m[i][j] = vals[i][j];
  return m;
}
// copy a matrix. remember matrices are ptrs
matrix mcp(matrix m) {
  matrix matcp = matalloc(m.x, m.y);
  for (int i = 0; i < m.x; i++)
    for (int j = 0; j < m.x; j++)
      matcp.m[i][j] = m.m[i][j];
  return matcp;
}

// equality testing
int v2eq(v2 a, v2 b) {
  if (
    a.x == b.x &&
    a.y == b.y
  )
    return 1;
  else
    return 0;
}
int v3eq(v3 a, v3 b) {
  if (
    a.x == b.x &&
    a.y == b.y &&
    a.z == b.z
  )
    return 1;
  else
    return 0;
}
int v4eq(v4 a, v4 b) {
  if (
    a.x == b.x &&
    a.y == b.y &&
    a.z == b.z &&
    a.w == b.w
  )
    return 1;
  else
    return 0;
}

// matrix equality
int meq(matrix a, matrix b) {
  // check dimensions
  if (a.x != b.x || a.y != b.y)
    return 0;
  // check values
  for (int i = 0; i < a.x; i++)
    for (int j = 0; j < a.x; j++)
      if (a.m[i][j] != b.m[i][j])
        return 0;
  return 1;
}

// pack a vector into a float ptr
float* v2top(v2 v) {
  float* fp = fpalloc(2);
  fp[0] = v.x;
  fp[1] = v.y;
  return fp;
}
float* v3top(v3 v) {
  float* fp = fpalloc(3);
  fp[0] = v.x;
  fp[1] = v.y;
  fp[2] = v.z;
  return fp;
}
float* v4top(v4 v) {
  float* fp = fpalloc(4);
  fp[0] = v.x;
  fp[1] = v.y;
  fp[2] = v.z;
  fp[3] = v.w;
  return fp;
}

// ptr to vec
v2 ptov2(float* p) {
  v2 v = {p[0], p[1]};
  return v;
}
v3 ptov3(float* p){
  v3 v = {p[0], p[1], p[2]};
  return v;
}
v4 ptov4(float* p){
  v4 v = {p[0], p[1], p[2], p[3]};
  return v;
}


// ptr alloc
float* fpalloc(int n) {
  float* fp = malloc(sizeof(float) * n);
  return fp;
}
float** ftalloc(int x, int y) {
  float** ft = malloc(sizeof(float*) * x);
  for (int i = 0; i < x; i++) {
    ft[i] = malloc(sizeof(float) * y);
  }
  return ft;
}
void ftfree(float** ft, int x) {
  for (int i = 0; i < x; i++) {
    free(ft[i]);
  }
  free(ft);
}

// matrix struct allocation
matrix matalloc(int x, int y) {
  matrix m = {ftalloc(x, y), x, y};
  return m;
}
void matfree(matrix m) {
  ftfree(m.m, m.x);
}

// projection matrix (camera matrix)
matrix m4proj(int w, int h, float fovd, float znear, float zfar) {
  float a = (float)h/(float)w;
  float fovr = dtor(fovd / 2.0f);
  float f = 1.0 / tan(fovr / 2.0f);
  float q = zfar / (zfar - znear);
  const float vals[4][4] = {
    {a*f, 0,          0, 0},
    {  0, f,          0, 0},
    {  0, 0,          q, 1},
    {  0, 0, -znear * q, 0}
  };
  return new_m4(vals);
}

// point at matrix (look at)
matrix m4lookat(v4 pos, v4 target, v4 up) {
  v4 new_forward = vnorm(vsub(target, pos));
  v4 new_up = vnorm(vsub(up, vscl(new_forward, vdot(up, new_forward))));
  v4 new_right = vcross(new_up, new_forward);
  const float vals[4][4] = {
    {new_right.x,   new_right.y,   new_right.z,   0},
    {new_up.x,      new_up.y,      new_up.z,      0},
    {new_forward.x, new_forward.y, new_forward.z, 0},
    {pos.x,         pos.y,         pos.z,         1},
  };
  return new_m4(vals);
}

matrix m4xrot(float r) {
  const float vals[4][4] = {
    {1,  0,      0,      0},
    {0,  cos(r), sin(r), 0},
    {0, -sin(r), cos(r), 0},
    {0,  0,      0,      0}
  };
  return new_m4(vals);
}
matrix m4yrot(float r) {
  const float vals[4][4] = {
    {cos(r),  0, sin(r), 0},
    {0,       1, 0,      0},
    {-sin(r), 0, cos(r), 0},
    {0,       0, 0,      1},
  };
  return new_m4(vals);
}
matrix m4zrot(float r) {
  const float vals[4][4] = {
    {cos(r),  sin(r), 0, 0},
    {-sin(r), cos(r), 0, 0},
    {0,       0, 1,      0},
    {0,       0, 0,      1},
  };
  return new_m4(vals);
}
matrix m4invxy() {
  matrix m = m4id();
  m.m[0][0] = -1;
  m.m[1][1] = -1;
  return m;
}
matrix m4empty() {
  const float vals[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
  };
  return new_m4(vals);
}
matrix m4trans(float x, float y, float z) {
  matrix m = m4id();
  m.m[3][0] = x;
  m.m[3][1] = y;
  m.m[3][2] = z;
  return m;
}
// allocate and return a 4x4 identity matrix
matrix m4id() {
  matrix m = matalloc(4, 4);
  for (int i = 0; i < 4; i++)
      m.m[i][i] = 1.0f;
  return m;
}

matrix m4invert(matrix m) {
  matrix inverted = m4empty();
  inverted.m[0][0] = m.m[0][0];
  inverted.m[0][1] = m.m[1][0];
  inverted.m[0][2] = m.m[2][0];
  inverted.m[0][3] = 0;
  inverted.m[1][0] = m.m[0][1];
  inverted.m[1][1] = m.m[1][1];
  inverted.m[1][2] = m.m[2][1];
  inverted.m[1][3] = 0;
  inverted.m[2][0] = m.m[0][2];
  inverted.m[2][1] = m.m[1][2];
  inverted.m[2][2] = m.m[2][2];
  inverted.m[2][3] = 0;
  inverted.m[3][0] = -(
    m.m[3][0] * inverted.m[0][0] +
    m.m[3][1] * inverted.m[1][0] +
    m.m[3][2] * inverted.m[2][0]
  );
  inverted.m[3][1] = -(
    m.m[3][0] * inverted.m[0][1] +
    m.m[3][1] * inverted.m[1][1] +
    m.m[3][2] * inverted.m[2][1]
  );
  inverted.m[3][2] = -(
    m.m[3][0] * inverted.m[0][2] +
    m.m[3][1] * inverted.m[1][2] +
    m.m[3][2] * inverted.m[2][2]
  );
  inverted.m[3][3] = 1;
  return inverted;
}

// matrix multiplication
matrix mxm(matrix m1, matrix m2) {
  matrix m = m4empty();
  for (int i = 0; i < m1.x; i++)
   for (int j = 0; j < m1.y; j++)
     m.m[i][j] = m1.m[i][0] * m2.m[0][j] +
                 m1.m[i][1] * m2.m[1][j] +
                 m1.m[i][2] * m2.m[2][j] +
                 m1.m[i][3] * m2.m[3][j];
  return m;
}

v4 mxv(matrix m, v4 v) {
  v4 product = {
    v.x * m.m[0][0] +
    v.y * m.m[1][0] +
    v.z * m.m[2][0] +
    v.w * m.m[3][0],
    v.x * m.m[0][1] +
    v.y * m.m[1][1] +
    v.z * m.m[2][1] +
    v.w * m.m[3][1],
    v.x * m.m[0][2] +
    v.y * m.m[1][2] +
    v.z * m.m[2][2] +
    v.w * m.m[3][2],
    v.x * m.m[0][3] +
    v.y * m.m[1][3] +
    v.z * m.m[2][3] +
    v.w * m.m[3][3],
  };
  return product;
}

// math util prototypes
float rtod(float rad){
  return rad * 180.0f / PI;
}
float dtor(float deg){
  return deg * PI/ 180.0f;
}
float flim(float x, float lim) {
  return x < -lim ? -lim : x > lim ? lim : x;
}

// print functions
void printv2(v2 v){
  printf("v2 [%.2f, %.2f]\n", v.x, v.y);
}
void printv3(v3 v){
  printf("v3 [%.2f, %.2f, %.2f]\n", v.x, v.y, v.z);
}
void printv4(v4 v){
  printf("v4 [%.2f, %.2f, %.2f, %.2f]\n", v.x, v.y, v.z, v.w);
}
void printm(matrix m){
  for (int i = 0; i < m.x; i++) {
    if (i == 0) printf("m  ");
    else printf("   ");
    printf("[");
    for (int j = 0; j < m.y; j++) {
      printf("%.2f", m.m[i][j]);
      if (j != m.y - 1) printf(", ");
    }
    printf("]\n");
  }
}

// TEST FUNCTION //
void test() {
  printf("vector creation and math test:\n");
  v2 a = new_v2(1.0, 2.0);
  v3 b = new_v3(a, 3.0);
  v3 c = new_v3(3.0, 2.0, 1.0);
  v4 d = new_v4(4.0, 3.0, 2.0, 1.0);
  v4 e = new_v4(a, a);
  printv(a);
  printv(b);
  printv(c);
  printv(d);
  printv(e);
  printf("projection matrix test:\n");
  // define a projection matrix
  int w, h;
  float fov, znear, zfar;
  w = 1920;
  h = 1080;
  fov = 90;
  znear = 0.1;
  zfar = 1000;
  matrix proj = m4proj(w, h, fov, znear, zfar);
  matrix projcp = mcp(proj);
  printm(proj);
  printm(projcp);
  matfree(proj);
  printm(projcp);
  matfree(projcp);
}


int main() {
  test();
}
