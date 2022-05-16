template<typename T> T const *GetValuePointer(Vector2D<T> const &data) {
  return &data.x;
}

template<typename T> T const *GetValuePointer(Vector3D<T> const &data) {
  return &data.x;
}

template<typename T> T const *GetValuePointer(Vector4D<T> const &data) {
  return &data.x;
}

template<typename T> T const *GetValuePointer(Matrix4x4<T> const &data) {
  return &(data[0].x);
}
