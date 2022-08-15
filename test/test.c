#include "vec.h"
int main() {
  v2 a = {1.0, 2.0};
  v2 b = {3.0, 4.0};
  v2 c = vadd(a, b);
  vprint(c);
  return 0;
}
