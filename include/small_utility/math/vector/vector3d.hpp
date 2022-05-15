#ifndef COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR3D_HPP_
#define COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR3D_HPP_

template<typename T> Vector3D<T>::Vector3D() : x(0.0f), y(0.0f), z(0.0f) {}

template<typename T> Vector3D<T>::Vector3D(T scalar)
    : x(scalar), y(scalar), z(scalar) {}

template<typename T> Vector3D<T>::Vector3D(T _x, T _y, T _z)
    : x(_x), y(_y), z(_z) {}

template<typename T> Vector3D<T>::Vector3D(Vector3D<T> const &rhs)
    : x(rhs.x), y(rhs.y), z(rhs.z) {}

template<typename T> Vector3D<T>::~Vector3D() {}

#endif // !COMMAND_AND_DOMINATE_SRC_MATH_VECTOR_VECTOR3D_HPP_
