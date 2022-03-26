#include "log/logger.h"

#include <cstdarg>
//#include <cstring>
#include <map>

#include "string/string.h"
#include "utility/utility.h"

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
  va_End(args);

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

#undef ProcessLogMessageInfo(pattern, content, log_level, log_message)

int const ProcessLogMessageInfo(
    char const *const pattern, char const *const content, int const line,
    char const *const file_name, char const *const function_name,
    LogLevel const log_level, string_stuff::String &log_message) {
  string_stuff::String pattern_string(pattern);
  string_stuff::String buffer_string; // used to store argument name.
  // Matches patterns with true string.
  std::map<string_stuff::String, string_stuff::String> pattern_map;
  pattern_map["content"] = content;
  pattern_map["line"] = string_stuff::String(line);
  pattern_map["file_name"] = file_name;
  ParseFunctionName(function_name, pattern_map["function_name"]);
  pattern_map["time"] =
    string_stuff::String(time_stuff::Time().SetToCurrentTime(),
                         "$(year)-$(month)-$(day) $(hour):$(minute):$(second)");
  pattern_map["log_level"] = string_stuff::String(log_level);
  std::map<string_stuff::String, string_stuff::String>::iterator it;

  for (int i = 0; i != pattern_string.Size(); ) {
    int left_position = pattern_string.Find("$(", i);
    if (utility::Equal(left_position, -1)) {
      log_message += pattern_string.SubStringIndex(i, pattern_string.Size()-1);
      break;
    }
    int right_position = pattern_string.Find(")", left_position);
    if (utility::Equal(right_position, -1)) {
      log_message += pattern_string.SubStringIndex(left_position + 2,
                                                   pattern_string.Size() - 1);
      break;
    }
    if (left_position > i) {
      log_message += pattern_string.SubStringIndex(i, left_position - 1);
    }
    i = right_position + 1;
    buffer_string = pattern_string.SubStringIndex(left_position + 2,
                                                  right_position - 1);
    it = pattern_map.find(buffer_string);
    buffer_string = utility::Equal(it, pattern_map.end()) ?  "" : (*it).second;
    log_message += buffer_string;
  }

  return 0;
}

void ParseFunctionName(char const *const raw_function_name,
                       string_stuff::String &destiniation) {
  string_stuff::String source_function_name(raw_function_name);
  destiniation = source_function_name.SubStringIndex(
      source_function_name.Find(' ') + 1, source_function_name.Size() - 1);
}

/*
   void Debug(char const *format, ...) {
   va_list args;
   va_start(args, format);
   Logger::PrintFormat(LogLevel::kLogLevelDebug, format, args);
   va_End(args);
   }

   void Info(char const *format, ...) {
   va_list args;
   va_start(args, format);
   Logger::PrintFormat(LogLevel::kLogLevelInfo, format, args);
   va_End(args);
   }

   void Warning(char const *format, ...) {
   va_list args;
   va_start(args, format);
   Logger::PrintFormat(LogLevel::kLogLevelWarning, format, args);
   va_End(args);
   }

   void Error(char const *format, ...) {
   va_list args;
   va_start(args, format);
   Logger::PrintFormat(LogLevel::kLogLevelError, format, args);
   va_End(args);
   }

   void Fatal(char const *format, ...) {
   va_list args;
   va_start(args, format);
   Logger::PrintFormat(LogLevel::kLogLevelError, format, args);
   va_End(args);
   }
   */

}

}
