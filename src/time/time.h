#ifndef SMALL_UTILITY_TIME_TIME_H_
#define SMALL_UTILITY_TIME_TIME_H_

#include <ctime>

namespace small_utility {

namespace time_stuff {

class Time {
 public:
  Time();
  Time(int const year, int const month, int const day, int const hour,
       int const minute, int const second, int const millisecond);
  Time(tm const &t);

  Time const &SetToCurrentTime();

  int const Year() const { return year_; }
  int const Month() const { return month_; }
  int const Day() const { return day_; }
  int const Hour() const { return hour_; }
  int const Minute() const { return minute_; }
  int const Second() const { return second_; }
  int const Millisecond() const { return millisecond_; }
 private:
  int year_, month_, day_, hour_, minute_, second_, millisecond_;
};

} // namespace time_stuff

} // namespace small_utility

#endif // !SMALL_UTILITY_TIME_TIME_H_
