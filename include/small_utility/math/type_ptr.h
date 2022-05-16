#ifndef COMMAND_AND_DOMINATE_MATH_TYPE_PTR_H_
#define COMMAND_AND_DOMINATE_MATH_TYPE_PTR_H_

#include "small_utility/math/vector/vector.h"
#include "small_utility/math/matrix/matrix.h"

template<typename T> T *GetValuePointer(Vector2D<T> const &data);
template<typename T> T *GetValuePointer(Vector3D<T> const &data);
template<typename T> T *GetValuePointer(Vector4D<T> const &data);
template<typename T> T *GetValuePointer(Matrix4x4<T> const &data);

#include "small_utility/math/type_ptr.hpp"

#endif  // COMMAND_AND_DOMINATE_MATH_TYPE_PTR_H_
