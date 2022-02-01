#ifndef SMALL_UTILITY_LOG_LOG_TARGET_H_
#define SMALL_UTILITY_LOG_LOG_TARGET_H_

#include "log/log_message_info.h"

class LogTarget {
 public:
  virtual void Write(LogMessageInfo const & log_message_info) = 0;
};

#endif // !SMALL_UTILITY_LOG_LOG_TARGET_H_
