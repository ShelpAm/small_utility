template<typename T> T *GetValuePointer(Vector2D<T> const &data) {
  return &data.x;
}

template<typename T> T *GetValuePointer(Vector3D<T> const &data) {
  return &data.x;
}

template<typename T> T *GetValuePointer(Vector4D<T> const &data) {
  return &data.x;
}

template<typename T> T *GetValuePointer(Matrix4x4<T> const &data) {
  return &data[0].x;
}
