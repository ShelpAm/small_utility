#include "small_utility.h"

#include <cstdio>

namespace small_utility {

void Sleep (int const time) {
  if (time < 0) {
    printf("[ERROR::small_utility::Sleep] The delay time is smaller than 0, "
           "as big as %i.\n", time);
    return;
  }
#ifdef linux
  timespec ts;
  ts.tv_sec = time / 1000;
  ts.tv_nsec = (time % 1000) * 1000 * 1000;
  int const error = nanosleep(&ts, nullptr);
  if (error == -1) {
    printf("[Prompt::small_utility::Sleep] Sleeping has been interrupted.");
  }
#elif defined WIN32 // linux
  Sleep(time);
#else // WIN32
  printf("[ERROR::small_utility::Sleep] No corresponding platform.");
#endif
}

}
