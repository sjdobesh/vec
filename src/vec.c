/**============*
 *             *
 *    vec.c    *
 *             *
 *==================================*
 * author: samantha jane            *
 * desc: vector implementation file *
 *==================================*
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "vec.h"

#define PI 3.1415926535

/*---- util functions ----*/

/** radians to degrees */
float rtod(float rad){
  return rad * 180.0f / PI;
}

/** degrees to radians */
float dtor(float deg){
  return deg * PI / 180.0f;
}

/** float limit */
float flim(float x, float lim) {
  return x < -lim ? -lim : x > lim ? lim : x;
}

float fminf(float, float);

/*---- vector functions ----*/

/* vector addition core */

/**
 * vector 2 vector 2 addition.
 * elementwise sum of a and b.
 *
 * @param a v2
 * @param b v2
 * @return v2 a + b
 */
v2 v2v2add(v2 a, v2 b){
  return (v2) {
    .x = a.x + b.x,
    .y = a.y + b.y
  };
}
/**
 * vector 3 vector 3 addition.
 * elementwise sum of a and b.
 *
 * @param a v3
 * @param b v3
 * @return v3 a + b
 */
v3 v3v3add(v3 a, v3 b){
  return (v3) {
    .x = a.x + b.x,
    .y = a.y + b.y,
    .z = a.z + b.z
  };
}
/**
 * vector 4 vector 4 addition.
 * elementwise sum of a and b.
 *
 * @param a v4
 * @param b v4
 * @return v4 a + b
 */
v4 v4v4add(v4 a, v4 b){
  return (v4) {
    .x = a.x = a.x + b.x,
    .y = a.y = a.y + b.y,
    .z = a.z = a.z + b.z,
    .w = a.w = a.w + b.w
  };
}

/* vector addition promotions */

/**
 * vector 2 vector 3 addition.
 * elementwise sum of a and b.
 * a promoted before summation.
 *
 * @param a v2
 * @param b v3
 * @return v3 a + b
 */
v3 v2v3add(v2 a, v3 b) {
  v3 promoted = {
    .x = a.x,
    .y = a.y,
    .z = 0
  };
  return v3v3add(promoted, b);
}

/**
 * vector 2 vector 4 addition.
 * elementwise sum of a and b.
 * a promoted before summation.
 *
 * @param a v2
 * @param b v4
 * @return v4 a + b
 */
v4 v2v4add(v2 a, v4 b) {
  v4 promoted = {
    .x = a.x,
    .y = a.y,
    .z = 0,
    .w = 0
  };
  return v4v4add(promoted, b);
}

/**
 * vector 3 vector 2 addition.
 * elementwise sum of a and b.
 * b promoted before summation.
 *
 * @param a v3
 * @param b v2
 * @return v3 a + b
 */
v3 v3v2add(v3 a, v2 b) {
  v3 promoted = {
    .x = b.x,
    .y = b.y,
    .z = 0
  };
  return v3v3add(a, promoted);
}

/**
 * vector 3 vector 4 addition.
 * elementwise sum of a and b.
 * a promoted before summation.
 *
 * @param a v3
 * @param b v4
 * @return v4 a + b
 */
v4 v3v4add(v3 a, v4 b) {
  v4 promoted = {
    .x = a.x,
    .y = a.y,
    .z = a.z,
    .w = 0
  };
  return v4v4add(promoted, b);
}

/**
 * vector 4 vector 2 addition.
 * elementwise sum of a and b.
 * b promoted before summation.
 *
 * @param a v4
 * @param b v2
 * @return v4 a + b
 */
v4 v4v2add(v4 a, v2 b) {
  v4 promoted = {
    .x = b.x,
    .y = b.y,
    .z = 0,
    .w = 0
  };
  return v4v4add(a, promoted);
}

/**
 * vector 4 vector 3 addition.
 * elementwise sum of a and b.
 * b promoted before summation.
 *
 * @param a v4
 * @param b v3
 * @return v4 a + b
 */
v4 v4v3add(v4 a, v3 b) {
  v4 promoted = {
    .x = b.x,
    .y = b.y,
    .z = 0,
    .w = 0
  };
  return v4v4add(a, promoted);
}

/* vector substraction core */

/**
 * vector 2 vector 2 substraction.
 * elementwise difference of a and b.
 *
 * @param a v2
 * @param b v2
 * @return v2 a - b
 */
v2 v2v2sub(v2 a, v2 b){
  return (v2) {
    .x = a.x - b.x,
    .y = a.y - b.y
  };
}

/**
 * vector 3 vector 3 substraction.
 * elementwise difference of a and b.
 *
 * @param a v3
 * @param b v3
 * @return v3 a - b
 */
v3 v3v3sub(v3 a, v3 b){
  return (v3) {
    .x = a.x - b.x,
    .y = a.y - b.y,
    .z = a.z - b.z
  };
}

/**
 * vector 4 vector 4 substraction.
 * elementwise difference of a and b.
 *
 * @param a v4
 * @param b v4
 * @return v4 a - b
 */
v4 v4v4sub(v4 a, v4 b){
  return (v4) {
    .x = a.x - b.x,
    .y = a.y - b.y,
    .z = a.z - b.z,
    .w = a.w - b.w
  };
}

/* vector substraction promotions */

/**
 * vector 2 vector 3 substraction.
 * elementwise difference of a and b.
 * a promoted before subtraction.
 *
 * @param a v2
 * @param b v3
 * @return v3 a - b
 */
v3 v2v3sub(v2 a, v3 b){
  v3 promoted = {
    .x = a.x,
    .y = a.y,
    .z = 0
  };
  return v3v3sub(promoted, b);
}

/**
 * vector 2 vector 4 substraction.
 * elementwise difference of a and b.
 * a promoted before subtraction.
 *
 * @param a v2
 * @param b v4
 * @return v4 a - b
 */
v4 v2v4sub(v2 a, v4 b){
  v4 promoted = {
    .x = a.x,
    .y = a.y,
    .z = 0,
    .w = 0
  };
  return v4v4sub(promoted, b);
}

/**
 * vector 3 vector 2 substraction.
 * elementwise difference of a and b.
 * b promoted before subtraction.
 *
 * @param a v3
 * @param b v2
 * @return v3 a - b
 */
v3 v3v2sub(v3 a, v2 b){
  v3 promoted = {
    .x = b.x,
    .y = b.y,
    .z = 0
  };
  return v3v3sub(a, promoted);
}

/**
 * vector 3 vector 4 substraction.
 * elementwise difference of a and b.
 * a promoted before subtraction.
 *
 * @param a v3
 * @param b v4
 * @return v4 a - b
 */
v4 v3v4sub(v3 a, v4 b){
  v4 promoted = {
    .x = a.x,
    .y = a.y,
    .z = a.z,
    .w = 0
  };
  return v4v4sub(promoted, b);
}

/**
 * vector 4 vector 2 substraction.
 * elementwise difference of a and b.
 * b promoted before subtraction.
 *
 * @param a v4
 * @param b v2
 * @return v4 a - b
 */
v4 v4v2sub(v4 a, v2 b){
  v4 promoted = {
    .x = b.x,
    .y = b.y,
    .z = 0,
    .w = 0
  };
  return v4v4sub(a, promoted);
}

/**
 * vector 4 vector 3 substraction.
 * elementwise difference of a and b.
 * b promoted before subtraction.
 *
 * @param a v4
 * @param b v3
 * @return v4 a - b
 */
v4 v4v3sub(v4 a, v3 b){
  v4 promoted = {
    .x = b.x,
    .y = b.y,
    .z = b.z,
    .w = 0
  };
  return v4v4sub(a, promoted);
}

/* vector multiply core */

/**
 * vector 2 vector 2 multiplication.
 * elementwise product of a and b.
 *
 * @param a v2
 * @param b v2
 * @return v2 a * b
 */
v2 v2v2mul(v2 a, v2 b){
  return (v2) {
    .x = a.x * b.x,
    .y = a.y * b.y
  };
}

/**
 * vector 3 vector 3 multiplication.
 * elementwise product of a and b.
 *
 * @param a v3
 * @param b v3
 * @return v3 a * b
 */
v3 v3v3mul(v3 a, v3 b){
  return (v3) {
    .x = a.x * b.x,
    .y = a.y * b.y,
    .z = a.z * b.z
  };
}

/**
 * vector 4 vector 4 multiplication.
 * elementwise product of a and b.
 *
 * @param a v4
 * @param b v4
 * @return v4 a * b
 */
v4 v4v4mul(v4 a, v4 b){
  return (v4) {
    .x = a.x * b.x,
    .y = a.y * b.y,
    .z = a.z * b.z,
    .w = a.w * b.w
  };
}

/* vector multiplication promotion */

/**
 * vector 2 vector 3 multiplication.
 * elementwise product of a and b.
 * a promoted before multiplication.
 *
 * @param a v2
 * @param b v3
 * @return v3 a * b
 */
v3 v2v3mul(v2 a, v3 b){
  v3 promoted = {
    .x = a.x,
    .y = a.y,
    .z = 0
  };
  return v3v3mul(promoted, b);
}

/**
 * vector 2 vector 4 multiplication.
 * elementwise product of a and b.
 * a promoted before multiplication.
 *
 * @param a v2
 * @param b v4
 * @return v4 a * b
 */
v4 v2v4mul(v2 a, v4 b){
  v4 promoted = {
    .x = a.x,
    .y = a.y,
    .z = 0,
    .w = 0
  };
  return v4v4mul(promoted, b);
}

/**
 * vector 3 vector 2 multiplication.
 * elementwise product of a and b.
 * b promoted before multiplication.
 *
 * @param a v3
 * @param b v2
 * @return v3 a * b
 */
v3 v3v2mul(v3 a, v2 b){
  v3 promoted = {
    .x = b.x,
    .y = b.y,
    .z = 0
  };
  return v3v3mul(a, promoted);
}

/**
 * vector 3 vector 4 multiplication.
 * elementwise product of a and b.
 * a promoted before multiplication.
 *
 * @param a v3
 * @param b v4
 * @return v4 a * b
 */
v4 v3v4mul(v3 a, v4 b){
  v4 promoted = {
    .x = a.x,
    .y = a.y,
    .z = a.z,
    .w = 0
  };
  return v4v4mul(promoted, b);
}

/**
 * vector 4 vector 2 multiplication.
 * elementwise product of a and b.
 * b promoted before multiplication.
 *
 * @param a v4
 * @param b v2
 * @return v4 a * b
 */
v4 v4v2mul(v4 a, v2 b){
  v4 promoted = {
    .x = b.x,
    .y = b.y,
    .z = 0,
    .w = 0
  };
  return v4v4mul(a, promoted);
}

/**
 * vector 4 vector 3 multiplication.
 * elementwise product of a and b.
 * b promoted before multiplication.
 *
 * @param a v4
 * @param b v3
 * @return v4 a * b
 */
v4 v4v3mul(v4 a, v3 b){
  v4 promoted = {
    .x = b.x,
    .y = b.y,
    .z = b.z,
    .w = 0
  };
  return v4v4mul(a, promoted);
}

/* vector division core */

/**
 * vector 2 vector 2 division.
 * elementwise quotient of a and b.
 *
 * @param a v2
 * @param b v2
 * @return v2 a / b
 */
v2 v2v2div(v2 a, v2 b){
  return (v2) {
    a.x = a.x / b.x,
    a.y = a.y / b.y
  };
}

/**
 * vector 3 vector 3 division.
 * elementwise quotient of a and b.
 *
 * @param a v3
 * @param b v3
 * @return v3 a / b
 */
v3 v3v3div(v3 a, v3 b){
  return (v3) {
    a.x / b.x,
    a.y / b.y,
    a.z / b.z
  };
}

/**
 * vector 4 vector 4 division.
 * elementwise quotient of a and b.
 *
 * @param a v4
 * @param b v4
 * @return v4 a / b
 */
v4 v4v4div(v4 a, v4 b){
  return (v4) {
    a.x / b.x,
    a.y / b.y,
    a.z / b.z,
    a.w / b.w
  };
}

/* vector division promotion */

/**
 * vector 2 vector 3 division.
 * elementwise quotient of a and b.
 * a promoted before division.
 *
 * @param a v2
 * @param b v3
 * @return v3 a / b
 */
v3 v2v3div(v2 a, v3 b){
  v3 promoted = {
    .x = a.x,
    .y = a.y,
    .z = 0
  };
  return v3v3div(promoted, b);
}

/**
 * vector 2 vector 4 division.
 * elementwise quotient of a and b.
 * a promoted before division.
 *
 * @param a v2
 * @param b v4
 * @return v4 a / b
 */
v4 v2v4div(v2 a, v4 b){
  v4 promoted = {
    .x = a.x,
    .y = a.y,
    .z = 0,
    .w = 0
  };
  return v4v4div(promoted, b);
}

/**
 * vector 3 vector 2 division.
 * elementwise quotient of a and b.
 * b promoted before division.
 *
 * @param a v3
 * @param b v2
 * @return v3 a / b
 */
v3 v3v2div(v3 a, v2 b){
  v3 promoted = {
    .x = b.x,
    .y = b.y,
    .z = 0
  };
  return v3v3div(a, promoted);
}

/**
 * vector 3 vector 3 division.
 * elementwise quotient of a and b.
 * a promoted before division.
 *
 * @param a v3
 * @param b v4
 * @return v4 a / b
 */
v4 v3v4div(v3 a, v4 b){
  v4 promoted = {
    .x = a.x,
    .y = a.y,
    .z = a.z,
    .w = 0
  };
  return v4v4div(promoted, b);
}

/**
 * vector 4 vector 2 division.
 * elementwise quotient of a and b.
 * a promoted before division.
 *
 * @param a v4
 * @param b v2
 * @return v4 a / b
 */
v4 v4v2div(v4 a, v2 b){
  v4 promoted = {
    .x = b.x,
    .y = b.y,
    .z = 0,
    .w = 0
  };
  return v4v4div(a, promoted);
}

/**
 * vector 4 vector 3 division.
 * elementwise quotient of a and b.
 * a promoted before division.
 *
 * @param a v4
 * @param b v3
 * @return v4 a / b
 */
v4 v4v3div(v4 a, v3 b){
  v4 promoted = {
    .x = b.x,
    .y = b.y,
    .z = b.z,
    .w = 0
  };
  return v4v4div(a, promoted);
}

/* magnitude function */

/**
 * vector 2 magnitude.
 * get the length of the vector v.
 *
 * @param v v2
 * @return float
 */
float v2mag(v2 v){
  return sqrt(
    pow(v.x, 2) + pow(v.y, 2)
  );
}

/**
 * vector 3 magnitude.
 * get the length of the vector v.
 *
 * @param v v3
 * @return float
 */
float v3mag(v3 v){
  return sqrt(
    pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)
  );
}

/**
 * vector 4 magnitude.
 * get the length of the vector v.
 *
 * @param v v4
 * @return float
 */
float v4mag(v4 v){
  return sqrt(
    pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2) + pow(v.w, 2)
  );
}

/* vector scale */

/**
 * vector 2 scale.
 * scale the vector v by s.
 *
 * @param v v2
 * @param s float
 * @return v2 v * s
 */
v2 v2scl(v2 v, float s){
  return (v2) {
    .x = v.x * s,
    .y = v.y * s
  };
}

/**
 * vector 3 scale.
 * scale the vector v by s.
 *
 * @param v v3
 * @param s float
 * @return v3 v * s
 */
v3 v3scl(v3 v, float s){
  return (v3) {
    .x = v.x * s,
    .y = v.y * s,
    .z = v.z * s
  };
}

/**
 * vector 4 scale.
 * scale the vector v by s.
 *
 * @param v v4
 * @param s float
 * @return v4 v * s
 */
v4 v4scl(v4 v, float s){
  return (v4) {
    .x = v.x * s,
    .y = v.y * s,
    .z = v.z * s,
    .w = v.w * s
  };
}

/* vector limit */

/**
 * vector 2 limit.
 * limits the magnitude of v to s.
 *
 * @param v v2
 * @param s float
 * @return v2 v with magnitude of at most s.
 */
v2 v2lim(v2 v, float s){
  float mag = v2mag(v);
  float frac = fminf(mag, s) / mag;
  return v2scl(v, frac);
}

/**
 * vector 3 limit.
 * limits the magnitude of v to s.
 *
 * @param v v3
 * @param s float
 * @return v3 v with magnitude of at most s.
 */
v3 v3lim(v3 v, float s){
  float mag = v3mag(v);
  float frac = fminf(mag, s) / mag;
  return v3scl(v, frac);
}

/**
 * vector 4 limit.
 * limits the magnitude of v to s.
 *
 * @param v v4
 * @param s float
 * @return v4 v with magnitude of at most s.
 */
v4 v4lim(v4 v, float s){
  float mag = v4mag(v);
  float frac = fminf(mag, s) / mag;
  return v4scl(v, frac);
}


/* vector dot product core */

/**
 * vector 2 vector 2 dot product.
 * return a scalar describing the similarity of a and b.
 *
 * @param a v2
 * @param b v2
 * @return float a . b
 */
float v2v2dot(v2 a, v2 b){
  return (
    (a.x * b.x) +
    (a.y * b.y)
  );
}

/**
 * vector 3 vector 3 dot product.
 * return a scalar describing the similarity of a and b.
 *
 * @param a v3
 * @param b v3
 * @return float a . b
 */
float v3v3dot(v3 a, v3 b){
  return (
    (a.x * b.x) +
    (a.y * b.y) +
    (a.z * b.z)
  );
}

/**
 * vector 4 vector 4 dot product.
 * return a scalar describing the similarity of a and b.
 *
 * @param a v4
 * @param b v4
 * @return float a . b
 */
float v4v4dot(v4 a, v4 b){
  return (
    (a.x * b.x) +
    (a.y * b.y) +
    (a.z * b.z) +
    (a.w * b.w)
  );
}

/* vector dot product promotion */

/**
 * vector 2 vector 3 dot product.
 * return a scalar describing the similarity of a and b.
 * a promoted before computation.
 *
 * @param a v2
 * @param b v3
 * @return float a . b
 */
float v2v3dot(v2 a, v3 b){
  v3 promoted = {
    .x = a.x,
    .y = a.y,
    .z = 0
  };
  return v3v3dot(promoted, b);
}

/**
 * vector 2 vector 4 dot product.
 * return a scalar describing the similarity of a and b.
 * a promoted before computation.
 *
 * @param a v2
 * @param b v4
 * @return float a . b
 */
float v2v4dot(v2 a, v4 b){
  v4 promoted = {
    .x = a.x,
    .y = a.y,
    .z = 0,
    .w = 0
  };
  return v4v4dot(promoted, b);
}

/**
 * vector 3 vector 2 dot product.
 * return a scalar describing the similarity of a and b.
 * b promoted before computation.
 *
 * @param a v3
 * @param b v2
 * @return float a . b
 */
float v3v2dot(v3 a, v2 b){
  v3 promoted = {
    .x = b.x,
    .y = b.y,
    .z = 0
  };
  return v3v3dot(a, promoted);
}

/**
 * vector 3 vector 4 dot product.
 * return a scalar describing the similarity of a and b.
 * a promoted before computation.
 *
 * @param a v3
 * @param b v4
 * @return float a . b
 */
float v3v4dot(v3 a, v4 b){
  v4 promoted = {
    .x = a.x,
    .y = a.y,
    .z = a.z,
    .w = 0
  };
  return v4v4dot(promoted, b);
}

/**
 * vector 4 vector 2 dot product.
 * return a scalar describing the similarity of a and b.
 * b promoted before computation.
 *
 * @param a v4
 * @param b v2
 * @return float a . b
 */
float v4v2dot(v4 a, v2 b){
  v4 promoted = {
    .x = b.x,
    .y = b.y,
    .z = 0,
    .w = 0
  };
  return v4v4dot(a, promoted);
}

/**
 * vector 4 vector 3 dot product.
 * return a scalar describing the similarity of a and b.
 * b promoted before computation.
 *
 * @param a v4
 * @param b v3
 * @return float a . b
 */
float v4v3dot(v4 a, v3 b){
  v4 promoted = {
    .x = b.x,
    .y = b.y,
    .z = b.z,
    .w = 0
  };
  return v4v4dot(a, promoted);
}

/* vector normalize */


/**
 * vector 2 normalize.
 * return its input but divided by its own length.
 *
 * @param v v2
 * @return v2 v / v.len
 */
v2 v2norm(v2 v){
  float len = vmag(v);
  return (v2) {
    .x = v.x / len,
    .y = v.y / len
  };
}

/**
 * vector 3 normalize.
 * return its input but divided by its own length.
 *
 * @param v v3
 * @return v3 v / v.len
 */
v3 v3norm(v3 v){
  float len = vmag(v);
  return (v3) {
    .x = v.x / len,
    .y = v.y / len,
    .z = v.z / len
  };
}

/**
 * vector 4 normalize.
 * return its input but divided by its own length.
 *
 * @param v v4
 * @return v4 v / v.len
 */
v4 v4norm(v4 v){
  float len = vmag(v);
  return (v4) {
    .x = v.x / len,
    .y = v.y / len,
    .z = v.z / len,
    .w = v.w / len
  };
}

/* vector cross product core */


/**
 * vector 4 vector 4 cross product.
 * calculate the norm from a and b.
 *
 * @param a v4
 * @param b v4
 * @return v4 a x b
 */
v4 v4v4cross(v4 a, v4 b){
  return (v4) {
    (a.y * b.z - a.z * b.y),
    (a.x * b.z - a.z * b.x),
    (a.x * b.y - a.y * b.x),
    0
  };
}

/**
 * vector 3 vector 3 cross product.
 * calculate the norm from a and b.
 * note output promotion, .w = 0.
 *
 * @param a v3
 * @param b v3
 * @return v4 a x b
 */
v4 v3v3cross(v3 a, v3 b){
  v4 promotion_a = {
    .x = a.x,
    .y = a.y,
    .z = a.z,
    .w = 0
  };
  v4 promotion_b = {
    .x = b.x,
    .y = b.y,
    .z = b.z,
    .w = 0
  };
  return v4v4cross(promotion_a, promotion_b);
}

/**
 * vector 2 vector 2 cross product.
 * calculate the norm from a and b.
 * note return promotion to v4, .w = 0.
 *
 * @param a v2
 * @param b v2
 * @return v4 a x b
 */
v4 v2v2cross(v2 a, v2 b){
  v4 promotion_a = {
    .x = a.x,
    .y = a.y,
    .z = 0,
    .w = 0
  };
  v4 promotion_b = {
    .x = b.x,
    .y = b.y,
    .z = 0,
    .w = 0
  };
  return v4v4cross(promotion_a, promotion_b);
}

/* vector cross product promotion */

/**
 * vector 4 vector 2 cross product.
 * calculate the norm from a and b.
 * b promoted before cross.
 *
 * @param a v4
 * @param b v2
 * @return v4 a x b
 */
v4 v4v2cross(v4 a, v2 b) {
  v4 promotion = {
    .x = b.x,
    .y = b.y,
    .z = 0,
    .w = 0
  };
  return v4v4cross(a, promotion);
}

/**
 * vector 4 vector 3 cross product.
 * calculate the norm from a and b.
 * b promoted before cross.
 *
 * @param a v4
 * @param b v3
 * @return v4 a x b
 */
v4 v4v3cross(v4 a, v3 b) {
  v4 promotion = {
    .x = b.x,
    .y = b.y,
    .z = b.z,
    .w = 0
  };
  return v4v4cross(a, promotion);
}

/**
 * vector 3 vector 2 cross product.
 * calculate the norm from a and b.
 * b promoted before cross.
 * note return promotion to v4, .w = 0.
 *
 * @param a v3
 * @param b v2
 * @return v4 a x b
 */
v4 v3v2cross(v3 a, v2 b) {
  v3 promotion = {
    .x = b.x,
    .y = b.y,
    .z = 0
  };
  return v3v3cross(a, promotion);
}

/**
 * vector 3 vector 4 cross product.
 * calculate the norm from a and b.
 * a promoted before cross.
 * note return promotion to v4, .w = 0.
 *
 * @param a v3
 * @param b v4
 * @return v4 a x b
 */
v4 v3v4cross(v3 a, v4 b) {
  v3 promotion = {
    .x = b.x,
    .y = b.y,
    .z = b.z
  };
  return v3v3cross(a, promotion);
}

/**
 * vector 2 vector 3 cross product.
 * calculate the norm from a and b.
 * a promoted before cross.
 * note return promotion to v4, .w = 0.
 *
 * @param a v2
 * @param b v3
 * @return v4 a x b
 */
v4 v2v3cross(v2 a, v3 b) {
  v3 promotion = {
    .x = a.x,
    .y = a.y,
    .z = 0
  };
  return v3v3cross(promotion, b);
}

/**
 * vector 2 vector 4 cross product.
 * calculate the norm from a and b.
 * a promoted before cross.
 * note return promotion to v4, .w = 0.
 *
 * @param a v2
 * @param b v4
 * @return v4 a x b
 */
v4 v2v4cross(v2 a, v4 b) {
  v3 promotion_a = {
    .x = a.x,
    .y = a.y,
    .z = 0
  };
  v3 promotion_b = {
    .x = b.x,
    .y = b.y,
    .z = b.z
  };
  return v3v3cross(promotion_a, promotion_b);
}

/* vector equality core */

/**
 * vector 2 vector 2 equal comparison.
 * check of contents of a and b are identical.
 *
 * @param a v2
 * @param b v2
 * @return boolean
 */
int v2v2eq(v2 a, v2 b) {
  return (
    a.x == b.x &&
    a.y == b.y
  ) ? 1 : 0;
}

/**
 * vector 3 vector 3 equal comparison.
 * check of contents of a and b are identical.
 *
 * @param a v3
 * @param b v3
 * @return boolean
 */
int v3v3eq(v3 a, v3 b) {
  return (
    a.x == b.x &&
    a.y == b.y &&
    a.z == b.z
  ) ? 1 : 0;
}

/**
 * vector 4 vector 4 equal comparison.
 * check if contents of a and b are identical.
 *
 * @param a v4
 * @param b v4
 * @return boolean
 */
int v4v4eq(v4 a, v4 b) {
  return (
    a.x == b.x &&
    a.y == b.y &&
    a.z == b.z &&
    a.w == b.w
  ) ? 1 : 0;
}

/* vector equality promotion */

/**
 * vector 2 vector 3 equal comparison.
 * promotes a then checks if contents of a and b are identical.
 *
 * @param a v2
 * @param b v3
 * @return boolean
 */
int v2v3eq(v2 a, v3 b){
  v3 promotion = {
    .x = a.x,
    .y = a.y,
    .z = 0
  };
  return v3v3eq(promotion, b);
}

/**
 * vector 2 vector 4 equal comparison.
 * promotes a then checks if contents of a and b are identical.
 *
 * @param a v2
 * @param b v4
 * @return boolean
 */
int v2v4eq(v2 a, v4 b){
  v4 promotion = {
    .x = a.x,
    .y = a.y,
    .z = 0,
    .w = 0
  };
  return v4v4eq(promotion, b);
}

/**
 * vector 3 vector 2 equal comparison.
 * promotes b then checks if contents of a and b are identical.
 *
 * @param a v3
 * @param b v2
 * @return boolean
 */
int v3v2eq(v3 a, v2 b){
  v3 promotion = {
    .x = b.x,
    .y = b.y,
    .z = 0
  };
  return v3v3eq(a, promotion);
}

/**
 * vector 3 vector 4 equal comparison.
 * promotes a then checks if contents of a and b are identical.
 *
 * @param a v3
 * @param b v4
 * @return boolean
 */
int v3v4eq(v3 a, v4 b){
  v4 promotion = {
    .x = a.x,
    .y = a.y,
    .z = a.z,
    .w = 0
  };
  return v4v4eq(promotion, b);
}

/**
 * vector 4 vector 2 equal comparison.
 * promotes b then checks if contents of a and b are identical.
 *
 * @param a v4
 * @param b v2
 * @return boolean
 */
int v4v2eq(v4 a, v2 b){
  v4 promotion = {
    .x = b.x,
    .y = b.y,
    .z = 0,
    .w = 0
  };
  return v4v4eq(a, promotion);
}

/**
 * vector 4 vector 3 equal comparison.
 * promotes b then checks if contents of a and b are identical.
 *
 * @param a v4
 * @param b v3
 * @return boolean
 */
int v4v3eq(v4 a, v3 b) {
  v4 promotion = {
    .x = b.x,
    .y = b.y,
    .z = b.z,
    .w = 0
  };
  return v4v4eq(a, promotion);
}

/*---- matrix functions ----*/

/**
 * matrix equal.
 *
 * @param a an m4
 * @param b another m4
 * @return a boolean for if the matrices a == b.
 */
int meq(m4 a, m4 b) {
  int i, j;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      if (a.m[i][j] != b.m[i][j])
        return 0;
  return 1;
}

/**
 * empty matrix.
 *
 * @return a matrix of all zeros
 */
m4 m4empty() {
  return (m4){{
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
  }};
}

/**
 * identity matrix.
 *
 * @return a 4x4 identity matrix.
 */
m4 m4id() {
  return (m4){{
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1},
  }};
}

/**
 * inverse x and y id matrix
 *
 * @return the identity matrix with a -1 in x and y pivot
 */
m4 m4invxyid() {
  return (m4){{
    {-1,  0, 0, 0},
    { 0, -1, 0, 0},
    { 0,  0, 1, 0},
    { 0,  0, 0, 1},
  }};
}

/**
 * translation matrix.
 *
 * trans rights :)
 *
 * @param x translation in x dimension
 * @param y translation in y dimension
 * @param z translation in z dimension
 * @return a 4x4 translation matrix for 3d space
 */
m4 m4trans(float x, float y, float z) {
  return (m4){{
    {x, 0, 0, 0},
    {0, y, 0, 0},
    {0, 0, z, 0},
    {0, 0, 0, 1}
  }};
}

/**
 * x rotation matrix.
 *
 * @param r rotation in radians
 * @return a rotation matrix
 */
m4 m4xrot(float r) {
  return (m4){{
    {1,  0,      0,      0},
    {0,  cos(r), sin(r), 0},
    {0, -sin(r), cos(r), 0},
    {0,  0,      0,      0}
  }};
}

/**
 * y rotation matrix.
 *
 * @param r rotation in radians
 * @return a rotation matrix
 */
m4 m4yrot(float r) {
  return (m4){{
    {cos(r),  0, sin(r), 0},
    {0,       1, 0,      0},
    {-sin(r), 0, cos(r), 0},
    {0,       0, 0,      1},
  }};
}

/**
 * z rotation matrix.
 *
 * @param r rotation in radians
 * @return a rotation matrix
 */
m4 m4zrot(float r) {
  return (m4){{
    {cos(r),  sin(r), 0, 0},
    {-sin(r), cos(r), 0, 0},
    {0,       0, 1,      0},
    {0,       0, 0,      1},
  }};
}

/**
 * invert a matrix.
 *
 * @param m an m4 to invert
 * @return
 */
m4 m4invert(m4 m) {
  m4 i = {{
    {m.m[0][0], m.m[1][0], m.m[2][0], 0},
    {m.m[0][1], m.m[1][1], m.m[2][1], 0},
    {m.m[0][2], m.m[1][2], m.m[2][2], 0}
  }};
  i.m[0][3] = -(
    m.m[3][0] * i.m[0][0] +
    m.m[3][1] * i.m[1][0] +
    m.m[3][2] * i.m[2][0]
  );
  i.m[1][3] = -(
    m.m[3][0] * i.m[0][1] +
    m.m[3][1] * i.m[1][1] +
    m.m[3][2] * i.m[2][1]
  );
  i.m[2][3] = -(
    m.m[3][0] * i.m[0][2] +
    m.m[3][1] * i.m[1][2] +
    m.m[3][2] * i.m[2][2]
  );
  i.m[3][3] = 1;
  return i;
}

/**
 * m4 multiplication.
 * multiply two 4x4 homogenous matrices.
 *
 * @param m1 m4
 * @param m2 m4
 * @returns m4 resulting from m1 right multiplied by m2
 */
m4 m4xm4(m4 m1, m4 m2) {
  int i, j;
  m4 m;
  for (i = 0; i < 4; i++)
   for (j = 0; j < 4; j++)
     m.m[i][j] = m1.m[i][0] * m2.m[0][j] +
                 m1.m[i][1] * m2.m[1][j] +
                 m1.m[i][2] * m2.m[2][j] +
                 m1.m[i][3] * m2.m[3][j];
  return m;
}

/**
 * matrix vector multiplication.
 * transform v by matrix m through right multiplication.
 *
 * @param m m4
 **/
v4 m4xv4(m4 m, v4 v) {
  return (v4){
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
}
v4 m4xv3(m4 m, v3 v) {
  v4 v1 = {v.x, v.y, v.z, 1};
  return m4xv4(m, v1);
}
v4 m4xv2(m4 m, v2 v) {
  v4 v1 = {v.x, v.y, 0, 1};
  return m4xv4(m, v1);
}

/**
 * projection matrix (camera matrix).
 *
 * @param w the width of the screen in pixels
 * @param h the hieght of the screen in pixels
 * @param fovd field of view in degrees (not radians!)
 * @param znear near clipping plane
 * @param zfar far clipping plane
 * @return projection matrix that converts from world to screen coordinates
 */
m4 m4proj(int w, int h, float fovd, float znear, float zfar) {
  float a = (float)h / (float)w;
  float fovr = dtor(fovd / 2.0f);
  float f = 1.0 / tan(fovr / 2.0f);
  float q = zfar / (zfar - znear);
  return (m4){{
    { a * f, 0,          0, 0},
    {     0, f,          0, 0},
    {     0, 0,          q, 1},
    {     0, 0, -znear * q, 0}
  }};
}

/**
 * look at/point at matrix.
 * create the necessary transform to rotate towards a position in space.
 *
 * @param pos
 * @param target
 * @param up
 * @return m4 with rotation transform
 */
m4 m4lookat(v4 pos, v4 target, v4 up) {
  v4 new_forward = v4norm(v4v4sub(target, pos));
  v4 new_up = v4norm(v4v4sub(up, v4scl(new_forward, v4v4dot(up, new_forward))));
  v4 new_right = v4v4cross(new_up, new_forward);
  return (m4){{
    {new_right.x,   new_right.y,   new_right.z,   0},
    {new_up.x,      new_up.y,      new_up.z,      0},
    {new_forward.x, new_forward.y, new_forward.z, 0},
    {pos.x,         pos.y,         pos.z,         1},
  }};
}

/* print functions */

/**
 * vector 2 print.
 *
 * @param v v2
 * @return void
 */
void v2print(v2 v){
  printf("v2 [ %.2f, %.2f ]\n", v.x, v.y);
}

/**
 * vector 3 print.
 *
 * @param v v3
 * @return void
 */
void v3print(v3 v){
  printf("v3 [ %.2f, %.2f, %.2f ]\n", v.x, v.y, v.z);
}

/**
 * vector 4 print.
 *
 * @param v v4
 * @return void
 */
void v4print(v4 v){
  printf("v4 [ %.2f, %.2f, %.2f, %.2f ]\n", v.x, v.y, v.z, v.w);
}

/**
 * matrix 4 print.
 *
 * @param m m4
 * @return void
 */
void mprint(m4 m) {
  printf("m4 [\n");
  printf("  %.2f, %.2f, %.2f, %.2f\n",
    m.m[0][0], m.m[0][1], m.m[0][2], m.m[0][3]);
  printf("  %.2f, %.2f, %.2f, %.2f\n",
    m.m[1][0], m.m[1][1], m.m[1][2], m.m[1][3]);
  printf("  %.2f, %.2f, %.2f, %.2f\n",
    m.m[2][0], m.m[2][1], m.m[2][2], m.m[2][3]);
  printf("  %.2f, %.2f, %.2f, %.2f\n",
    m.m[3][0], m.m[3][1], m.m[3][2], m.m[3][3]);
  printf("]\n");
}
