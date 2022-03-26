#include "utility/utility.h"

namespace small_utility {

namespace utility {

#if defined SMALL_UTILITY_LINUX
void SleepLinux (int const time) {
  if (time < 0) {
    printf("[ERROR::small_utility::Sleep] The delay time is smaller"
           "than 0, as big as %i.\n", time);
    return;
  }
  timespec ts;
  ts.tv_sec = time / 1000;
  ts.tv_nsec = (time % 1000) * 1000 * 1000;
  int const error = nanosleep(&ts, nullptr);
  if (error == -1) {
    printf("[Warn::small_utility::Sleep] Sleeping has been interrupted.");
  }
}

FILE *PopenLinux(char const *command, char const *type) {
  return popen(command, type);
}

int const PcloseLinux(FILE* file_ptr) {
  return pclose(file_ptr);
}

#elif defined SMALL_UTILITY_WINDOWS // SMALL_UTILITY_LINUX

void SleepWindows(int const time) {
  if (time < 0) {
    printf("[ERROR::small_utility::Sleep] The delay time is smaller"
           "than 0, as big as %i.\n", time);
    return;
  }

  Sleep(time);
}

FILE *PopenWindows(char const *command, char const *type) {
  return _popen(command, type);
}

int const PcloseWindows(FILE* file_ptr) {
  return _pclose(file_ptr);
}

#else
# error no_corresponding_platform
#endif

} // namespace utility

} // namespace small_utility
