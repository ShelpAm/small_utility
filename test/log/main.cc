#include "log/logger.h"

#include "string/string.h"

using namespace small_utility;

int main() {
  string_stuff::String message;
  time_stuff::Time time; time.SetToCurrentTime();
  log_stuff::ProcessLogMessageInfo(
      "$(time) $(log_level) $(file_name):$(line) in $(function_name): $(ontent)\n",
      //"$(function_name) $(file_name)",
      "test_", time, log_stuff::LogLevel::kLogLevelInfo, message);


  //log_stuff::LogMessageInfo message("11111\n", "11", time_stuff::time(2022, 2, 14, 8, 33, 1, 0), log_stuff::LogLevel::kLogLevelInfo);

  string_stuff::Print(message);

  return 0;
}
