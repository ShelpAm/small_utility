#ifndef COMMAND_AND_DOMINIATE_SRC_MATH_VECTOR_VECTOR3D_H_
#define COMMAND_AND_DOMINIATE_SRC_MATH_VECTOR_VECTOR3D_H_

#include "small_utility/math/vector/vector3d_forward.h"
#include <cmath>
#include <stdexcept>

template<typename T>
struct Vector3D {
 public:
  Vector3D();
  Vector3D(T scalar);
  Vector3D(T _x, T _y, T _z);
  Vector3D(Vector3D<T> const &rhs);
  ~Vector3D();
  T &operator[](int const index) {
    if (index < 0 || index > 2) {
      throw std::out_of_range("Vector3D index out of range");
    }
    return *(&x + index);
  }
  T operator[](int const index) const {
    if (index < 0 || index > 2) {
      throw std::out_of_range("Vector3D index out of range");
    }
    return *(&x + index);
  }

  T x, y, z;
};

template<typename T>
void operator+=(Vector3D<T> &lhs, T const rhs) {
  throw std::logic_error("test");
  lhs.x += rhs;
  lhs.y += rhs;
  lhs.z += rhs;
}

template<typename T> void operator+=(Vector3D<T> &lhs, Vector3D<T> const &rhs) {
  lhs.x += rhs.x;
  lhs.y += rhs.y;
  lhs.z += rhs.z;
}

template<typename T> Vector3D<T> operator/(Vector3D<T> const &lhs, T rhs) {
  return Vector3D<T>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

template<typename T> Vector3D<T> operator*(Vector3D<T> const &lhs, T rhs) {
  return Vector3D<T>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

template<typename T>
T Length(Vector3D<T> const &rhs) {
  return sqrt(rhs.x * rhs.x + rhs.y * rhs.y + rhs.z * rhs.z);
}

template<typename T>
Vector3D<T> Normalize(Vector3D<T> const &rhs) {
  return rhs / Length(rhs);
}

#include "small_utility/math/vector/vector3d.hpp"

#endif // !COMMAND_AND_DOMINIATE_SRC_MATH_VECTOR_VECTOR3D_H_
