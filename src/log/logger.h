#ifndef SMALL_UTILITY_LOG_LOGGER_H_
#define SMALL_UTILITY_LOG_LOGGER_H_

#if defined __linux__
# define __SMALL_UTILITY_FUNCTION_NAME__ __PRETTY_FUNCTION__
#elif defined _WIN32
# define __SMALL_UTILITY_FUNCTION_NAME__ __FUNCSIG__
#else
# error No corresponding platform.
#endif

#include <vector>

#include "file/file.h"
#include "log/log_level.h"
#include "log/log_message_info.h"
#include "log/log_target.h"
#include "string/string.h"
#include "time/time.h"

namespace small_utility {

namespace log_stuff {

class Logger {
 public:
  static Logger &Instance();

  void AddLogMessage(LogMessageInfo const &log_message_info);
  void WriteToTarget(LogTarget const &log_target);

 private:
  std::vector<LogMessageInfo> log_message_infos_;
  LogLevel minimum_log_level_;
};

int const ProcessLogMessageInfo(
      char const *const pattern, char const *const content, int const line,
      char const *const file_name, char const *const function_name,
      LogLevel const log_level,/* out */ string_stuff::String &log_message);

#define \
  ProcessLogMessageInfo(pattern, content, log_level, log_message) \
  ProcessLogMessageInfo(pattern, content, __LINE__, __FILE__,\
                        __SMALL_UTILITY_FUNCTION_NAME__, log_level, log_message)


//  destination: The output of this function. Its size_ shouldn't exceed
//    max_function_name_size_.
//  raw_function_name: The string from __PRETTY_FUNCTION__.
void ParseFunctionName(char const *const raw_function_name,
                       string_stuff::String &destination);

void Debug(char const *format, ...);
void Info(char const *format, ...);
void Warning(char const *format, ...);
void Error(char const *format, ...);
void Fatal(char const *format, ...);

} // namespace log_stuff

} // namespace small_utility

#endif // !SMALL_UTILITY_LOG_LOGGER_H_
