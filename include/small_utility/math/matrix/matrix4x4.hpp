#ifndef COMMAND_AND_DOMINATE_SRC_MATH_MATRIX_MATRIX4X4_HPP_
#define COMMAND_AND_DOMINATE_SRC_MATH_MATRIX_MATRIX4X4_HPP_

#include <cmath>

template<typename T> Matrix4x4<T>::Matrix4x4()
    : value{row_type(0), row_type(0), row_type(0), row_type(0)} {}

template<typename value_type> Matrix4x4<value_type>::Matrix4x4(
    value_type scalar)
    : value{row_type(scalar, 0, 0, 0),
            row_type(0, scalar, 0, 0),
            row_type(0, 0, scalar, 0),
            row_type(0, 0, 0, scalar)} {}

template<typename value_type> Matrix4x4<value_type>::Matrix4x4(
    value_type x0, value_type y0, value_type z0, value_type w0,
    value_type x1, value_type y1, value_type z1, value_type w1,
    value_type x2, value_type y2, value_type z2, value_type w2,
    value_type x3, value_type y3, value_type z3, value_type w3)
    : value{row_type(x0, y0, z0, w0),
            row_type(x1, y1, z1, w1),
            row_type(x2, y2, z2, w2),
            row_type(x3, y3, z3, w3)} {}

template<typename value_type> Matrix4x4<value_type>::~Matrix4x4() {}

// cross
template<typename T>
Matrix4x4<T> operator*(Matrix4x4<T> const &m1, Matrix4x4<T> const &m2) {
  Matrix4x4<T> return_buffer;
  for (int i = 0; i != 4; ++i) {
    for (int j = 0; j != 4; ++j) {
      for (int k = 0; k != 4; ++k) {
        return_buffer[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
  return return_buffer;
}

template<typename T>
Matrix4x4<T> Translate(Vector3D<T> const &tranlation) {
  Matrix4x4<T> return_buffer(1.0f);
  for (int i = 0; i != 3; ++i) {
    return_buffer[i][4] = tranlation[i];
  }
  return return_buffer;
}

// This function will return a matrix4x4 representing the clockwise ratation
// around direction.
template<typename T>
Matrix4x4<T> Rotate(float const radians, Vector3D<T> const &direction) {
  Matrix4x4<T> return_buffer;
  float const &t = radians;
  Vector3D<T> const &r = direction;
  float const _c = 1 - cos(t), c = cos(t), s = sin(t);
  T const rxy = r.x * r.y, rxz = r.x * r.z, ryz = r.y * r.z;
  T const rx2 = pow(r.x, 2), ry2 = pow (r.y, 2), rz2 = pow(r.z, 2);
  return_buffer[0][0] = c + rx2 * _c;
  return_buffer[1][1] = c + ry2 * _c;
  return_buffer[2][2] = c + rz2 * _c;
  return_buffer[3][3] = 1;
  return_buffer[0][1] = rxy * _c - r.z * s;
  return_buffer[1][0] = rxy * _c + r.z * s;
  return_buffer[0][2] = rxz * _c + r.y * s;
  return_buffer[2][0] = rxz * _c - r.y * s;
  return_buffer[1][2] = ryz * _c - r.x * s;
  return_buffer[2][1] = ryz * _c + r.x * s;
  return return_buffer;
}

template<typename T>
Matrix4x4<T> LookAt();

template<typename value_type> Matrix4x4<value_type> Perspective(
    value_type y_field_of_view, value_type aspect,
    value_type z_near, value_type z_far) {
  value_type const tan_half_y_field_of_view =
      tan(y_field_of_view / static_cast<value_type>(2));

  Matrix4x4<value_type> result(static_cast<value_type>(0));
  result[0][0] =
      static_cast<value_type>(1) / (aspect * tan_half_y_field_of_view);
  result[1][1] = static_cast<value_type>(1) / tan_half_y_field_of_view;
  result[2][2] = - (z_far + z_near) / (z_far - z_near);
  result[2][3] = static_cast<value_type>(1);
  result[3][2] =
      - static_cast<value_type>(2) * z_far * z_near / (z_far - z_near);
  return result;
}

#endif // !COMMAND_AND_DOMINATE_SRC_MATH_MATRIX_MATRIX4X4_HPP_
