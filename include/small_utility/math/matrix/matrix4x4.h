#ifndef COMMAND_AND_DOMINATE_SRC_MATH_MATRIX_MATRIX4X4_H_
#define COMMAND_AND_DOMINATE_SRC_MATH_MATRIX_MATRIX4X4_H_

#include "small_utility/math/matrix/matrix4x4_forward.h"
#include <cassert>
#include <cstdio>
#include "small_utility/math/vector/vector3d.h"
#include "small_utility/math/vector/vector4d.h"

template<typename value_type> struct Matrix4x4 {
 public:
  using T = value_type;
  using row_type = Vector4D<value_type>;

  Matrix4x4();
  Matrix4x4(value_type scalar);
  Matrix4x4(value_type x0, value_type y0, value_type z0, value_type w0,
            value_type x1, value_type y1, value_type z1, value_type w1,
            value_type x2, value_type y2, value_type z2, value_type w2,
            value_type x3, value_type y3, value_type z3, value_type w3);
  row_type &operator[](int index) {
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

#endif // !COMMAND_AND_DOMINATE_SRC_MATH_MATRIX_MATRIX4X4_H_
