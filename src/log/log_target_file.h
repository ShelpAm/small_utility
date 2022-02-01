#ifndef SMALL_UTILITY_LOG_LOG_TARGET_FILE_H_
#define SMALL_UTILITY_LOG_LOG_TARGET_FILE_H_

#include "log/log_target.h"

class LogTargetFile : public LogTarget {
 public:
  virtual void Write(LogMessageInfo const & log_message_info);
 private:
  FilePtr file_ptr_;
};

#endif // !SMALL_UTILITY_LOG_LOG_TARGET_FILE_H_
