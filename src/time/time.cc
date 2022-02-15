#include "time/time.h"

namespace small_utility {

namespace time_stuff {

time::time() : year_(0), month_(0), day_(0), hour_(0),
               minute_(0), second_(0), millisecond_(0) {}

time::time(int const year, int const month, int const day, int const hour,
           int const minute, int const second, int const millisecond)
    : year_(year), month_(month), day_(day), hour_(hour),
      minute_(minute), second_(second), millisecond_(millisecond) {}

time::time(tm const t)
    : year_(t.tm_year + 1900), month_(t.tm_mon + 1), day_(t.tm_mday),
      hour_(t.tm_hour), minute_(t.tm_min), second_(t.tm_sec), millisecond_(0)
{}

void time::set_to_current_time() {
  //here -------------------------------
  //clock_gettime();
}

}

}
