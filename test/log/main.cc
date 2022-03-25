#include "log/logger.h"

#include "string/string.h"

using namespace small_utility;

int main() {
  string_stuff::String message;
  log_stuff::ProcessLogMessageInfo(
      "$(time) $(log_level) in $(file_name):$(line) $(content)\n",
      "test_", time_stuff::Time().SetToCurrentTime(),
      log_stuff::LogLevel::kLogLevelInfo, message);


  //log_stuff::LogMessageInfo message("11111\n", "11", time_stuff::time(2022, 2, 14, 8, 33, 1, 0), log_stuff::LogLevel::kLogLevelInfo);

  string_stuff::Print(message);

  return 0;
}
