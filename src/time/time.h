#ifndef SMALL_UTILITY_TIME_TIME_H_
#define SMALL_UTILITY_TIME_TIME_H_

#include <ctime>

namespace small_utility {

namespace time_stuff {

class time {
 public:
  time();
  time(int const year, int const month, int const day, int const hour,
       int const minute, int const second, int const millisecond);
  time(tm const &t);

  void set_to_current_time();
 private:
  int year_, month_, day_, hour_, minute_, second_, millisecond_;
};

}

}

#endif // !SMALL_UTILITY_TIME_TIME_H_
