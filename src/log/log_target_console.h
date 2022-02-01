#ifndef COMMAND_AND_DOMINATE_SMALL_UTILITY_LOG_LOG_TARGET_CONSOLE_H_
#define COMMAND_AND_DOMINATE_SMALL_UTILITY_LOG_LOG_TARGET_CONSOLE_H_

#include "log/log_target.h"

class LogTargetConsole : public LogTarget {
 public:
  virtual void Write(LogMessageInfo const &log_message_info);
};

#endif // !COMMAND_AND_DOMINATE_SMALL_UTILITY_LOG_LOG_TARGET_CONSOLE_H_
