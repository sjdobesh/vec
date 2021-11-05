#ifndef _VEC_H_
#define _VEC_H_

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

#define vadd(a, b) _Generic ((a), \
  v2: v2add, \
  v3: v3add, \
  v4: v4add  \
) (a, b)
v2 v2add(v2 a, v2 b);
v3 v3add(v3 a, v3 b);
v4 v4add(v4 a, v4 b);

#define vsub(a, b) _Generic ((a), \
  v2: v2sub, \
  v3: v3sub, \
  v4: v4sub  \
) (a, b)
v2 v2sub(v2 a, v2 b);
v3 v3sub(v3 a, v3 b);
v4 v4sub(v4 a, v4 b);

#define vmul(a, b) _Generic ((a), \
  v2: v2mul, \
  v3: v3mul, \
  v4: v4mul  \
) (a, b)
v2 v2mul(v2 a, v2 b);
v3 v3mul(v3 a, v3 b);
v4 v4mul(v4 a, v4 b);

#define vdiv(a, b) _Generic ((a), \
  v2: v2div, \
  v3: v3div, \
  v4: v4div  \
) (a, b)
v2 v2div(v2 a, v2 b);
v3 v3div(v3 a, v3 b);
v4 v4div(v4 a, v4 b);

#define vlim(a, s) _Generic ((a), \
  v2: v2lim, \
  v3: v3lim, \
  v4: v4lim  \
) (a, s)
v2 v2lim(v2 a, float s);
v3 v3lim(v3 a, float s);
v4 v4lim(v4 a, float s);

#define vmag(v) _Generic ((v), \
  v2: v2mag, \
  v3: v3mag, \
  v4: v4mag  \
) (v)
float v2mag(v2 v);
float v3mag(v3 v);
float v4mag(v4 v);

#define vscl(a, s) _Generic ((a), \
  v2: v2scl, \
  v3: v3scl, \
  v4: v4scl  \
) (a, s)
v2 v2scl(v2 a, float s);
v3 v3scl(v3 a, float s);
v4 v4scl(v4 a, float s);

#define vdot(a, b) _Generic ((a), \
  v2: v2dot, \
  v3: v3dot, \
  v4: v4dot  \
) (a, b)
float v2dot(v2 a, v2 b);
float v3dot(v3 a, v3 b);
float v4dot(v4 a, v4 b);

#define vnorm(v) _Generic ((v), \
  v2: v2norm, \
  v3: v3norm, \
  v4: v4norm  \
) (v)
v2 v2norm(v2 v);
v3 v3norm(v3 v);
v4 v4norm(v4 v);

#define vcross(a, b) _Generic ((a), \
  v2: v2cross, \
  v3: v3cross, \
  v4: v4cross  \
) (a, b)
v2 v2cross(v2 a, v2 b);
v3 v3cross(v3 a, v3 b);
v4 v4cross(v4 a, v4 b);

// new struct functions
#define new_v2(x, y) _Generic ((x + y), \
  float: new_v2_f, \
  double: new_v2_f  \
) (x, y)
v2 new_v2_f(float x, float y);

#define new_v3(x, ...) _Generic ((x), \
  float:  new_v3_f, \
  double: new_v3_f, \
  v2:     new_v3_v2 \
) (x, __VA_ARGS__)
v3 new_v3_f(float x, ...);
v3 new_v3_v2(v2 v, ...);


#define va_opt(dummy, ...) \
  ( sizeof( (char[]){#__VA_ARGS__} ) == 1 ) ? "," : ""

#define new_v4_v(y) _Generic((y), \
  v2:     new_v4_v2v2, \
  float:  new_v4_v2,   \
  double: new_v4_v2    \
)
#define new_v4_default(y) _Generic((y), \
  float:  new_v4_f, \
  double: new_v4_f, \
  v3:     new_v4_v3,\
  default:new_v4_v3 \
)
#define new_v4(x, y, ...) _Generic((x), \
  v2:      new_v4_v(y), \
  default: new_v4_default(y)  \
) (x, y __VA_OPT__(,) __VA_ARGS__)

v4 new_v4_f(float x, float y, ...);
v4 new_v4_v2(v2 v, float y, ...);
v4 new_v4_v2v2(v2 a, v2 b);
v4 new_v4_v3(v3 v, float w);

matrix new_m4(const float vals[4][4]);

// equality functions
#define veq(a, b) _Generic ((a), \
  v2: v2eq, \
  v3: v3eq, \
  v4: v4eq  \
) (a, b)
int v2eq(v2 a, v2 b);
int v3eq(v3 a, v3 b);
int v4eq(v4 a, v4 b);
int meq(matrix a, matrix b);

// vec to ptr
#define vtop(v) _Generic ((v), \
  v2: v2top, \
  v3: v3top, \
  v4: v4top  \
) (v)
float* v2top(v2 v);
float* v3top(v3 v);
float* v4top(v4 v);

// ptr to vec
v2 ptov2(float* p);
v3 ptov3(float* p);
v4 ptov4(float* p);

// matrix util functions

// float table
float* fpalloc(int x);
float** ftalloc(int x, int y);
void ftfree(float** ft, int x);

// matrix struct
matrix matalloc(int x, int y);
void matfree(matrix m);
matrix mcp(matrix m);

// common matrices
matrix proj_mat(int w, int h, float fov, float znear, float zfar);
matrix xrot_mat(float r);
matrix yrot_mat(float r);
matrix zrot_mat(float r);
matrix invxy_mat();
matrix id_mat();
matrix empty_mat();
matrix trans_mat(float x, float y, float z);

// math util prototypes
float rtod(float rad);
float dtor(float deg);
float flim(float x, float lim);

// printing functions
#define printv(v) _Generic ((v), \
  v2: printv2, \
  v3: printv3, \
  v4: printv4  \
) (v)
void printv2(v2 v);
void printv3(v3 v);
void printv4(v4 v);
void printm(matrix m);

#endif
