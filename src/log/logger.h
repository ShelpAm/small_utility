#ifndef SMALL_UTILITY_LOG_LOGGER_H_
#define SMALL_UTILITY_LOG_LOGGER_H_

#include "log/logger_forward.h"

#include "file/file.h"

namespace small_utility {

namespace log_stuff {

class Logger {
 public:
  static Logger &GetInstance();

  void AddLogMessageInfo(LogMessageInfo const &log_message_info);
  void SetLogTarget(LogTargetPtr const &log_target_ptr) {
    log_target_ = log_target;
  }

  void WriteToTarget();
 private:
  std::vector<LogMessageInfo> log_message_infos_;
  LogLevel minimum_log_level_;
  LogTargetPtr log_target_ptr_;
};

enum class LogLevel : int {
  kLogLevelDebug = 1,
  kLogLevelInfo,
  kLogLevelWarning,
  kLogLevelError,
  kLogLevelFatal
};

// Parameter:
//  destination: The output of this function. Its size shouldn't exceed
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
