// std
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// custom
#include "vec.h"

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
v2 v2lim(v2 a, float s){
  a.x = flim(a.x, s);
  a.y = flim(a.y, s);
  return a;
}
v3 v3lim(v3 a, float s){
  a.x = flim(a.x, s);
  a.y = flim(a.y, s);
  a.z = flim(a.z, s);
  return a;
}
v4 v4lim(v4 a, float s){
  a.x = flim(a.x, s);
  a.y = flim(a.y, s);
  a.z = flim(a.z, s);
  a.w = flim(a.w, s);
  return a;
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
// scale function
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
// vector packing functions
v2 newv2(float x, float y) {
  v2 v = {x, y};
  return v;
}
v3 newv3(float x, float y, float z) {
  v3 v = {x, y, z};
  return v;
}
v4 newv4(float x, float y, float z, float w) {
  v4 v = {x, y, z, w};
  return v;
}
matrix newm4(const float vals[4][4]) {
  matrix m = matalloc(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      m.m[i][j] = vals[i][j];
    }
  }
  return m;
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


// math util prototypes
// float rad2deg(float rad){}
// float deg2rad(float deg){}
float flim(float x, float lim) {
  return (x < -lim) ? -lim : (x > lim) ? lim : x;
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

int main() {
  // test function //
  const float vals[4][4] = {
                {0.0, 0.0, 0.0, 0.0},
                {0.0, 0.0, 0.0, 0.0},
                {0.0, 0.0, 0.0, 0.0},
                {0.0, 0.0, 0.0, 0.0},
              };
  matrix m = newm4(vals);
  printm(m);
}
