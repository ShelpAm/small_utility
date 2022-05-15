#ifndef COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR4D_H_
#define COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR4D_H_

#include "small_utility/math/vector/vector4d_forward.h"
#include <stdexcept>

template<typename T> struct Vector4D {
 public:
  Vector4D(T scalar);
  Vector4D(T _x, T _y, T _z, T _w);
  T &operator[](int const index) {
    if (index < 0 || index > 3) {
      throw std::out_of_range("Vector4D index out of range");
    }
    return *(&x + index);
  }
  T operator[](int const index) const {
    if (index < 0 || index > 3) {
      throw std::out_of_range("Vector4D index out of range");
    }
    return *(&x + index);
  }
  ~Vector4D();

  T x, y, z, w;
};

#include "small_utility/math/vector/vector4d.hpp"

#endif // !COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR4D_H_
