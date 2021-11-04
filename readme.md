# Vector library in C
A probably very bad vector library written in C. Supports 2-4 dimensional vectors, arbitrarily sized and 4x4 homogenous matrices, and basic functions for graphics programming.

## Quick Start
Just include the headeronly file in the top level of the repository. The src modules can be manually compiled for testing.

### Header Only
```
#include "vec.h"
```

### Compile
```
git clone https://github.com/sjdobesh/vec
cd vec/src
make
```
## Use

### Basic Use Example
```c
v2 a = new_v2(1.0, 2.5);
v2 b = new_v2(3.0, 1.5);
a = vadd(a, b);
printv(a);
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
printv(c);
```
