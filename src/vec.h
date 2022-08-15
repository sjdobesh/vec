/**============*
 *             *
 *    vec.h    *
 *             *
 *==========================*
 * author: samantha jane    *
 * desc: vector header file *
 *==========================*
 */

#ifndef _VEC_H_
#define _VEC_H_

#include <stdlib.h>

/**
 * 2d float vector.
 */
typedef struct v2 {
  float x, y;
} v2;

/**
 * 3d float vector.
 */
typedef struct v3 {
  float x, y, z;
} v3;

/**
 * 4d float vector.
 */
typedef struct v4 {
  float x, y, z, w;
} v4;

/**
 * 2d 4x4 homogenous matrix.
 **/
typedef struct m4 {
  float m[4][4];
} m4;

/* util prototypes */
float rtod(float rad);
float dtor(float deg);
float flim(float x, float lim);

/* matrix prototypes */
m4 m4proj(int w, int h, float fov, float znear, float zfar);
m4 m4lookat(v4 pos, v4 target, v4 up);
m4 m4xrot(float r);
m4 m4yrot(float r);
m4 m4zrot(float r);
m4 m4invxy();
m4 m4id();
m4 m4empty();
m4 m4trans(float x, float y, float z);
m4 m4invert(m4 m);
m4 m4xm4(m4 a, m4 b);
int m4eq(m4 a, m4 b);
void mprint(m4 m);

/* generic prototypes */

/* vadd */
v2 v2v2add(v2 a, v2 b);
v3 v2v3add(v2 a, v3 b);
v4 v2v4add(v2 a, v4 b);
v3 v3v2add(v3 a, v2 b);
v3 v3v3add(v3 a, v3 b);
v4 v3v4add(v3 a, v4 b);
v4 v4v2add(v4 a, v2 b);
v4 v4v3add(v4 a, v3 b);
v4 v4v4add(v4 a, v4 b);

/* vsub */
v2 v2v2sub(v2 a, v2 b);
v3 v2v3sub(v2 a, v3 b);
v4 v2v4sub(v2 a, v4 b);
v3 v3v2sub(v3 a, v2 b);
v3 v3v3sub(v3 a, v3 b);
v4 v3v4sub(v3 a, v4 b);
v4 v4v2sub(v4 a, v2 b);
v4 v4v3sub(v4 a, v3 b);
v4 v4v4sub(v4 a, v4 b);

/* vmul */
v2 v2v2mul(v2 a, v2 b);
v3 v2v3mul(v2 a, v3 b);
v4 v2v4mul(v2 a, v4 b);
v3 v3v2mul(v3 a, v2 b);
v3 v3v3mul(v3 a, v3 b);
v4 v3v4mul(v3 a, v4 b);
v4 v4v2mul(v4 a, v2 b);
v4 v4v3mul(v4 a, v3 b);
v4 v4v4mul(v4 a, v4 b);

/* vmul */
v2 v2v2div(v2 a, v2 b);
v3 v2v3div(v2 a, v3 b);
v4 v2v4div(v2 a, v4 b);
v3 v3v2div(v3 a, v2 b);
v3 v3v3div(v3 a, v3 b);
v4 v3v4div(v3 a, v4 b);
v4 v4v2div(v4 a, v2 b);
v4 v4v3div(v4 a, v3 b);
v4 v4v4div(v4 a, v4 b);

/* vlim */
v2 v2lim(v2 v, float s);
v3 v3lim(v3 v, float s);
v4 v4lim(v4 v, float s);

/* vmag */
float v2mag(v2 v);
float v3mag(v3 v);
float v4mag(v4 v);

/* vscl */
v2 v2scl(v2 v, float s);
v3 v3scl(v3 v, float s);
v4 v4scl(v4 v, float s);

/* vdot */
float v2v2dot(v2 a, v2 b);
float v2v3dot(v2 a, v3 b);
float v2v4dot(v2 a, v4 b);
float v3v2dot(v3 a, v2 b);
float v3v3dot(v3 a, v3 b);
float v3v4dot(v3 a, v4 b);
float v4v2dot(v4 a, v2 b);
float v4v3dot(v4 a, v3 b);
float v4v4dot(v4 a, v4 b);

/* vnorm */
v2 v2norm(v2 v);
v3 v3norm(v3 v);
v4 v4norm(v4 v);

/* vcross */
v4 v2v2cross(v2 a, v2 b);
v4 v2v3cross(v2 a, v3 b);
v4 v2v4cross(v2 a, v4 b);
v4 v3v2cross(v3 a, v2 b);
v4 v3v3cross(v3 a, v3 b);
v4 v3v4cross(v3 a, v4 b);
v4 v4v2cross(v4 a, v2 b);
v4 v4v3cross(v4 a, v3 b);
v4 v4v4cross(v4 a, v4 b);

/* veq */
int v2v2eq(v2 a, v2 b);
int v2v3eq(v2 a, v3 b);
int v2v4eq(v2 a, v4 b);
int v3v2eq(v3 a, v2 b);
int v3v3eq(v3 a, v3 b);
int v3v4eq(v3 a, v4 b);
int v4v2eq(v4 a, v2 b);
int v4v3eq(v4 a, v3 b);
int v4v4eq(v4 a, v4 b);

/* mxv */
v4 m4xv2(m4 m, v2 v);
v4 m4xv3(m4 m, v3 v);
v4 m4xv4(m4 m, v4 v);


/* vprint */
void v2print(v2 v);
void v3print(v3 v);
void v4print(v4 v);

/* generic function macros */

/* switches for vadd */
#define v2add(b)_Generic ((b), \
  v2 : v2v2add, \
  v3 : v2v3add, \
  v4 : v2v4add  \
)
#define v3add(b)_Generic ((b), \
  v2 : v3v2add, \
  v3 : v3v3add, \
  v4 : v3v4add  \
)
#define v4add(b)_Generic ((b), \
  v2 : v4v2add, \
  v3 : v4v3add, \
  v4 : v4v4add  \
)
/**
 * vector addition.
 * sums a and b element wise.
 * vectors can be different dimensions,
 * the return vector will be of the
 * highest dimension passed in.
 *
 * @param a vector
 * @param b vector
 * @return an element wise sum vector
 */
#define vadd(a, b) _Generic ((a), \
  v2 : v2add(b), \
  v3 : v3add(b), \
  v4 : v4add(b) \
) (a, b)

/* switches for vsub */
#define v2sub(b)_Generic ((b), \
  v2 : v2v2sub, \
  v3 : v2v3sub, \
  v4 : v2v4sub  \
)
#define v3sub(b)_Generic ((b), \
  v2 : v3v2sub, \
  v3 : v3v3sub, \
  v4 : v3v4sub  \
)
#define v4sub(b)_Generic ((b), \
  v2 : v4v2sub, \
  v3 : v4v3sub, \
  v4 : v4v4sub  \
)
/**
 * vector subtraction.
 * subtracts b from a element wise.
 * vectors can be different dimensions,
 * the return vector will be of the
 * highest dimension passed in.
 *
 * @param a vector
 * @param b vector
 * @return an element wise difference vector
 */
#define vsub(a, b) _Generic ((a), \
  v2: v2sub(b), \
  v3: v3sub(b), \
  v4: v4sub(b)  \
) (a, b)

/* switches for vmul */
#define v2mul(b)_Generic ((b), \
  v2 : v2v2mul, \
  v3 : v2v3mul, \
  v4 : v2v4mul  \
)
#define v3mul(b)_Generic ((b), \
  v2 : v3v2mul, \
  v3 : v3v3mul, \
  v4 : v3v4mul  \
)
#define v4mul(b)_Generic ((b), \
  v2 : v4v2mul, \
  v3 : v4v3mul, \
  v4 : v4v4mul  \
)
/**
 * vector multiplication.
 * multiplies a and b element wise.
 * they must be the same dimensions.
 *
 * @param a N dimensional vector
 * @param b N dimensional vector
 * @return an N dimensional element wise product
 */
#define vmul(a, b) _Generic ((a), \
  v2: v2mul(b), \
  v3: v3mul(b), \
  v4: v4mul(b)  \
) (a, b)

/* switches for vmul */
#define v2div(b)_Generic ((b), \
  v2 : v2v2div, \
  v3 : v2v3div, \
  v4 : v2v4div  \
)
#define v3div(b)_Generic ((b), \
  v2 : v3v2div, \
  v3 : v3v3div, \
  v4 : v3v4div  \
)
#define v4div(b)_Generic ((b), \
  v2 : v4v2div, \
  v3 : v4v3div, \
  v4 : v4v4div  \
)
/**
 * vector division.
 * divides a by b element wise.
 * they must be the same dimensions.
 *
 * @param a N dimensional vector
 * @param b N dimensional vector
 * @return an N dimensional element wise product
 */
#define vdiv(a, b) _Generic ((a), \
  v2: v2div(b), \
  v3: v3div(b), \
  v4: v4div(b)  \
) (a, b)

/**
 * vector limit.
 * limit a vector v by scalar s.
 *
 * @param v N dimensional vector
 * @param s N dimensional vector
 * @return v with a mangitude no greater than s
 */
#define vlim(v , s) _Generic ((v), \
  v2: v2lim, \
  v3: v3lim, \
  v4: v4lim  \
) (v, s)

/**
 * vector magnitude.
 * get the scalar magnitude of vector v.
 *
 * @param v N dimensional vector
 * @return the magnitude of v
 */
#define vmag(v) _Generic ((v), \
  v2: v2mag, \
  v3: v3mag, \
  v4: v4mag  \
) (v)

/**
 * vector scale.
 * multiply the magnitude of vector v by scalar s.
 *
 * @param v N dimensional vector
 * @param v N dimensional vector
 * @return the magnitude of v
 */
#define vscl(v, s) _Generic ((v), \
  v2: v2scl, \
  v3: v3scl, \
  v4: v4scl  \
) (v, s)

/* switches for vdot */
#define v2dot(b)_Generic ((b), \
  v2 : v2v2dot, \
  v3 : v2v3dot, \
  v4 : v2v4dot  \
)
#define v3dot(b)_Generic ((b), \
  v2 : v3v2dot, \
  v3 : v3v3dot, \
  v4 : v3v4dot  \
)
#define v4dot(b)_Generic ((b), \
  v2 : v4v2dot, \
  v3 : v4v3dot, \
  v4 : v4v4dot  \
)
/**
 * vector dot product.
 * get the dot product of vectors a and b.
 *
 * @param a N dimensional vector
 * @param b N dimensional vector
 * @return a scalar describing the similarity of the vectors
 */
#define vdot(a, b) _Generic ((a), \
  v2: v2dot(b), \
  v3: v3dot(b), \
  v4: v4dot(b)  \
) (a, b)

/**
 * vector normalize.
 * normalize the vector v by dividing its elements by its magnitude.
 *
 * @param v N dimensional vector
 * @return a normalized v
 */
#define vnorm(v) _Generic ((v), \
  v2: v2norm, \
  v3: v3norm, \
  v4: v4norm  \
) (v)

/* switches for vcross. order matters! */
#define v2cross(b)_Generic ((b), \
  v2 : v2v2cross, \
  v3 : v2v3cross, \
  v4 : v2v4cross  \
)
#define v3cross(b)_Generic ((b), \
  v2 : v3v2cross, \
  v3 : v3v3cross, \
  v4 : v3v4cross  \
)
#define v4cross(b)_Generic ((b), \
  v2 : v4v2cross, \
  v3 : v4v3cross, \
  v4 : v4v4cross  \
)
/**
 * vector cross product.
 * all vectors will be promoted to v4 with zeroed .w.
 *
 * @param a N dimensional vector
 * @param b N dimensional vector
 * @return a v4 containing the cross product vector of a and b in r3
 */
#define vcross(a, b) _Generic ((a), \
  v2: v2cross(b), \
  v3: v3cross(b), \
  v4: v4cross(b)  \
) (a, b)

/* switches for veq */
#define v2eq(b)_Generic ((b), \
  v2 : v2v2eq, \
  v3 : v2v3eq, \
  v4 : v2v4eq  \
)
#define v3eq(b)_Generic ((b), \
  v2 : v3v2eq, \
  v3 : v3v3eq, \
  v4 : v3v4eq  \
)
#define v4eq(b)_Generic ((b), \
  v2 : v4v2eq, \
  v3 : v4v3eq, \
  v4 : v4v4eq  \
)
/**
 * vector equal.
 * promotes arguments to the same type and compares.
 *
 * @param a N dimensional vector
 * @param b N dimensional vector
 * @return a boolean for if a == b
 */
#define veq(a, b) _Generic ((a), \
  v2: v2eq(b), \
  v3: v3eq(b), \
  v4: v4eq(b)  \
) (a, b)

/**
 * matrix vector multiplication.
 * like Ax = b.
 *
 * @param m an m4
 * @param v an N dimensional vector
 * @return a new v4 with the matrix transform applied
 */
#define mxv(m, v) _Generic ((v), \
  v2: m4xv2, \
  v3: m4xv3, \
  v4: m4xv4 \
)(m, v)

/**
 * print an vector to terminal.
 *
 * @param v N dimensional vector
 * @return void
 */
#define vprint(v) _Generic ((v), \
  v2: v2print, \
  v3: v3print, \
  v4: v4print  \
) (v)

#endif
