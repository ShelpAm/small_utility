#include "time/time.h"

//#include <>

namespace small_utility {

namespace time_stuff {

Time::Time() : year_(0), month_(0), day_(0), hour_(0),
               minute_(0), second_(0), millisecond_(0) {}

Time::Time(int const year, int const month, int const day, int const hour,
           int const minute, int const second, int const millisecond)
    : year_(year), month_(month), day_(day), hour_(hour),
      minute_(minute), second_(second), millisecond_(millisecond) {}

Time::Time(tm const &t)
    : year_(t.tm_year + 1900), month_(t.tm_mon + 1), day_(t.tm_mday),
      hour_(t.tm_hour), minute_(t.tm_min), second_(t.tm_sec), millisecond_(0) {}

Time const &Time::SetToCurrentTime() {
  //Time_t
  //here -------------------------------
  //clock_getTime();
  return *this;
}

} // namespace time_stuff

} // namespace small_utility
