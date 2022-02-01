#ifndef SMALL_UTILITY_LOG_LOG_MESSAGE_INFO_H_
#define SMALL_UTILITY_LOG_LOG_MESSAGE_INFO_H_

#include "string/string.h"

namespace small_utility {

namespace log_stuff {

class LogMessageInfo {
 public:
  LogMessageInfo(char const *log_format, char const *content,
                 Time const &time, LogLevel const log_level);
 private:
  void ProcessMessageInfo(char const *log_format, char const *content,
                          Time const &time, LogLevel const log_level);
  string_stuff::String message_;
};

}

}

#endif // !SMALL_UTILITY_LOG_LOG_MESSAGE_INFO_H_
