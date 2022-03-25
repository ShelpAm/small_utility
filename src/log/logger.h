#ifndef SMALL_UTILITY_LOG_LOGGER_H_
#define SMALL_UTILITY_LOG_LOGGER_H_

#if defined __linux__
# define __SMALL_UTILITY_FUNCTION_NAME__ __PRETTY_FUNCTION__
#elif defined _WIN32
# define __SMALL_UTILITY_FUNCTION_NAME__ __FUNCSIG__
#else
# error No corresponding platform.
#endif

#include "log/logger_forward.h"

#include <vector>

#include "file/file.h"
#include "log/log_level.h"
#include "log/log_target.h"
#include "time/time.h"

namespace small_utility {

namespace log_stuff {

class Logger {
 public:
  static Logger &Instance();

  void AddLogMessage(string_stuff::String const &log_message);
  void WriteToTarget(LogTarget const &log_target);

 private:
  std::vector<string_stuff::String> log_messages_;
  LogLevel minimum_log_level_;
};

int const ProcessLogMessageInfo(
      char const *const pattern, char const *const content, int const line,
      char const *const file_name, char const *const function_name,
      time_stuff::Time const &time, LogLevel const log_level,
      /* out */ string_stuff::String &log_message);

#define \
  ProcessLogMessageInfo(pattern, content, time, log_level, log_message) \
  ProcessLogMessageInfo(pattern, content, __LINE__, __FILE__,\
                        __SMALL_UTILITY_FUNCTION_NAME__, time, log_level,\
                        log_message)


//  destination: The output of this function. Its size_ shouldn't exceed
//    max_function_name_size_.
//  raw_function_name: The string from __PRETTY_FUNCTION__.
void ParseFunctionName(char *destination, char const *raw_function_name);

void Debug(char const *format, ...);
void Info(char const *format, ...);
void Warning(char const *format, ...);
void Error(char const *format, ...);
void Fatal(char const *format, ...);

}

}

#endif // !SMALL_UTILITY_LOG_LOGGER_H_
