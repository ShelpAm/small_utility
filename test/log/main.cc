#include <cstdio>

#include "log/logger.h"

using namespace small_utility;

int main() {
  log_stuff::LogMessageInfo message("$(content)-\\$(real_content),$(time)-\\$(real_time),$($(log_level)-\\$(real_log_level).\n", "$(real_content)", __FILE__, __LINE__, __func__, time_stuff::time(2022, 2, 14, 8, 33, 1, 0), log_stuff::LogLevel::kLogLevelInfo);


  //log_stuff::LogMessageInfo message("11111\n", "11", time_stuff::time(2022, 2, 14, 8, 33, 1, 0), log_stuff::LogLevel::kLogLevelInfo);

  printf("%s", message.message().ToCString());

  return 0;
}
