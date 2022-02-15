#include "log/logger.h"

#include <cstdarg>
#include <cstring>
#include <ctime>

#include "file/file.h"

namespace small_utility {

namespace log_stuff {

/*
void Logger::PrintFormat(LogLevel const log_level, char const *format, ...) {
  if (static_cast<int>(log_level_) < static_cast<int>(log_level) {
    return;
  }

  static char const *format_string = "[%s][%s][%s:%i][%s] %s";

  char log_time_string[20];
  time_t raw_time;
  time(&raw_time);
  tm *time_info = localtime(&raw_time);
  strftime(log_time_string, 20, "%F %T", time_info);

  char log_level_string[8];
  if (log_level == LogLevel::kLogLevelError) {
    strcpy(log_level_string, "Error");
  } else if (log_level == LogLevel::kLogLevelWarning) {
    strcpy(log_level_string, "Warning");
  } else if (log_level == LogLevel::kLogLevelInfo) {
    strcpy(log_level_string, "Info");
  } else if (log_level == LogLevel::kLogLevelDebug) {
    strcpy(log_level_string, "Debug");
  }

  static int const max_function_name_size_ = 128;
  char function_name[max_function_name_size_];
  ParseFunctionName(function_name, __PRETTY_FUNCTION__);

  char content[max_content_size_];
  va_list args;
  va_start(args, format);
  vsprintf(content, format, args);
  va_end(args);

  if (log_target_ == LogTarget::kLogTargetConsole) {
    printf(
        format_string, log_time_string, log_level_string,
        __FILE__, __LINE__, function_name, content);
  } else if (log_target_ == LogTarget::kLogTargetFile) {
    log_file_->PrintFormat(
        format_string, log_time_string, log_level_string,
        __FILE__, __LINE__, function_name, content);
  }

  return;
}
*/

void ParseFunctionName(char *destination, char const *raw_function_name) {
  strcpy(destination, "please finish this");
  /*   UNFINISHED     */
}

/*
void Debug(char const *format, ...) {
  va_list args;
  va_start(args, format);
  Logger::PrintFormat(LogLevel::kLogLevelDebug, format, args);
  va_end(args);
}

void Info(char const *format, ...) {
  va_list args;
  va_start(args, format);
  Logger::PrintFormat(LogLevel::kLogLevelInfo, format, args);
  va_end(args);
}

void Warning(char const *format, ...) {
  va_list args;
  va_start(args, format);
  Logger::PrintFormat(LogLevel::kLogLevelWarning, format, args);
  va_end(args);
}

void Error(char const *format, ...) {
  va_list args;
  va_start(args, format);
  Logger::PrintFormat(LogLevel::kLogLevelError, format, args);
  va_end(args);
}

void Fatal(char const *format, ...) {
  va_list args;
  va_start(args, format);
  Logger::PrintFormat(LogLevel::kLogLevelError, format, args);
  va_end(args);
}
*/

}

}
