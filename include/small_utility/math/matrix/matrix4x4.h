#ifndef COMMAND_AND_DOMINATE_SRC_MATH_MATRIX_MATRIX4X4_H_
#define COMMAND_AND_DOMINATE_SRC_MATH_MATRIX_MATRIX4X4_H_

#include "small_utility/math/matrix/matrix4x4_forward.h"
#include <stdexcept>
#include "small_utility/math/vector/vector3d.h"
#include "small_utility/math/vector/vector4d.h"

template<typename T> struct Matrix4x4 {
  using row_type = Vector4D<T>;
 public:
  Matrix4x4();
  Matrix4x4(T scalar);
  Matrix4x4(T x0, T y0, T z0, T w0,
            T x1, T y1, T z1, T w1,
            T x2, T y2, T z2, T w2,
            T x3, T y3, T z3, T w3);
  row_type &operator[](int index) {
    if (index < 0 || index > 3) {
      throw std::out_of_range("Matrix4x4 index out of range");
    }
    return value[index];
  }
  row_type const &operator[](int index) const {
    if (index < 0 || index > 3) {
      throw std::out_of_range("Matrix4x4 index out of range");
    }
    return value[index];
  }
  ~Matrix4x4();

  row_type value[4];
};

// cross
template<typename T>
Matrix4x4<T> operator*(Matrix4x4<T> const &m1, Matrix4x4<T> const &m2);

template<typename T>
Matrix4x4<T> Translate(Vector3D<T> const &tranlation);

// This function will return a matrix4x4 representing the clockwise ratation
// around direction.
template<typename T>
Matrix4x4<T> Rotate(float const radians, Vector3D<T> const &direction);

template<typename T>
Matrix4x4<T> LookAt();

template<typename T>
Matrix4x4<T> Perspective(T y_field_of_view, T aspect, T z_near, T z_far);

#include "small_utility/math/matrix/matrix4x4.hpp"

#endif  // COMMAND_AND_DOMINATE_SRC_MATH_MATRIX_MATRIX4X4_H_
