#ifndef SMALL_UTILITY
#define SMALL_UTILITY

#ifdef linux
#include <time.h>
#elif defined WIN32 // linux
#include <windows.h>
#endif // WIN32

namespace small_utility {

// The unit of this function is millisecond.
void Sleep (int const time);

}

#endif // !SMALL_UTILITY
