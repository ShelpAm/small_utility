#include "log/log_message_info.h"

namespace small_utility {

namespace log_stuff {

Logger::LogMessageInfo(char const *log_format, char const *content,
                       Time const &time, LogLevel const log_level) {
  ProcessMessageInfo(log_format, content, time, log_level);
}

void Logger::ProcessMessageInfo(char const *log_format, char const *content,
                                Time const &time, LogLevel const log_level) {
  
}

}

}
