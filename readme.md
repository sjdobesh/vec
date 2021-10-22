# Vector library in C
A probably very bad vector library written in C. Supports 2-4 dimensional vectors, arbitrarily sized and 4x4 homogenous matrices, and basic functions for graphics programming.

## Quick Start
Just include the headeronly file. The src modules can be manually compiled for testing.

### Header Only
```
#include "headeronly-vec.h"
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
v2 a = newv2(1.0, 2.5);
v2 b = newv2(3.0, 1.5);
a = vadd(a, b);
```
