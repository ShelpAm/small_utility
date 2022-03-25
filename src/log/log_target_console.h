#ifndef SMALL_UTILITY_LOG_LOG_TARGET_CONSOLE_H_
#define SMALL_UTILITY_LOG_LOG_TARGET_CONSOLE_H_

#include "log/log_target.h"

namespace small_utility {

namespace log_stuff {

class LogTargetConsole : public LogTarget {
 public:
  virtual void Write(string_stuff::String const &log_message_info);
};

}

}

#endif // !SMALL_UTILITY_LOG_LOG_TARGET_CONSOLE_H_
