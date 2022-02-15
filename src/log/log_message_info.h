#ifndef SMALL_UTILITY_LOG_LOG_MESSAGE_INFO_H_
#define SMALL_UTILITY_LOG_LOG_MESSAGE_INFO_H_

#include "log/log_level.h"
#include "string/string.h"
#include "time/time.h"

namespace small_utility {

namespace log_stuff {

class LogMessageInfo {
 public:
  LogMessageInfo(
      char const *log_format, char const *content, char const *file_name,
      int const line, char const *function_name, time_stuff::time const &t,
      LogLevel const log_level);
  string_stuff::String message() const { return message_; }
 private:
  void ProcessMessageInfo(
      char const *log_format, char const *content, char const*file_name,
      int const line, char const *function_name, time_stuff::time const &t,
      LogLevel const log_level);
  string_stuff::String message_;
};

}

}

#endif // !SMALL_UTILITY_LOG_LOG_MESSAGE_INFO_H_
