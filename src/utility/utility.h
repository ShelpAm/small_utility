#if !defined SMALL_UTILITY_UTILITY_UTILITY_H_
#define SMALL_UTILITY_UTILITY_UTILITY_H_

#include <cstdio>

#if defined __linux__
#include <time.h>
#elif defined _WIN32 // __linux__
#include <windows.h>
#endif // _WIN32

namespace small_utility {

namespace utility {

// The unit of this function is millisecond.
inline void Sleep (int const time) {
  if (time < 0) {
    printf("[ERROR::small_utility::Sleep] The delay time is smaller"
           "than 0, as big as %i.\n", time);
    return;
  }
#if defined __linux__
  timespec ts;
  ts.tv_sec = time / 1000;
  ts.tv_nsec = (time % 1000) * 1000 * 1000;
  int const error = nanosleep(&ts, nullptr);
  if (error == -1) {
    printf("[Warn::small_utility::Sleep] Sleeping has been interrupted.");
  }
#elif defined _WIN32 // linux
  Sleep(time);
#else // WIN32
  printf("[ERROR::small_utility::Sleep] No corresponding platform.");
#endif
}

template<typename type>
inline void Swap(type &lhs, type &rhs) {
  type temp(lhs);
  lhs = rhs;
  rhs = temp;
}

// Provide an interface, which is to decide if the to object is equal.
template<typename left_type, typename right_type>
inline bool Equal(left_type const &lhs, right_type const &rhs) {
  return lhs == rhs;
}

// Provide an interface, which is to decide if the to object is Unequal.
template<typename left_type, typename right_type>
inline bool Unequal(left_type const &lhs, right_type const &rhs) {
  return lhs != rhs;
}

template<typename left_type, typename right_type>
inline bool operator!=(left_type const &lhs, right_type const &rhs) {
  return !(lhs == rhs);
}

template<typename type>
inline type operator+(type const &lhs, type const &rhs) {
  return type(lhs) += rhs;
}

} // namespace utility

} // namespace small_utility

#endif // !SMALL_UTILITY_UTILITY_UTILITY_H_
