#include "small_utility/math/matrix/matrix.h"
#include "small_utility/math/type_ptr.h"

int main () {
  Matrix4x4 m1(2), m2(1);
  m1 * m2;
  GetValuePointer(m1);

  return 0;
}
