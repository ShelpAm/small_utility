#if !defined SMALL_UTILITY_UTILITY_SMALL_UTILITY_H_
#define SMALL_UTILITY_UTILITY_SMALL_UTILITY_H_

#if defined linux
#include <time.h>
#elif defined WIN32 // linux
#include <windows.h>
#endif // WIN32

namespace small_utility {

// The unit of this function is millisecond.
void Sleep (int const time);

template<typename type>
inline void swap(type &lhs, type &rhs) {
  type temp(lhs);
  lhs = rhs;
  rhs = temp;
}

// Provide an interface, which is to decide if the to object is equal.
template<typename left_type, typename right_type>
inline bool equal(left_type const &lhs, right_type const &rhs) {
  return lhs == rhs;
}

// Provide an interface, which is to decide if the to object is unequal.
template<typename left_type, typename right_type>
inline bool unequal(left_type const &lhs, right_type const &rhs) {
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

}

#endif // !SMALL_UTILITY_UTILITY_SMALL_UTILITY_H_
