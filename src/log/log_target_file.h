#ifndef SMALL_UTILITY_LOG_LOG_TARGET_FILE_H_
#define SMALL_UTILITY_LOG_LOG_TARGET_FILE_H_

#include "file/file.h"
#include "log/log_target.h"

namespace small_utility {

namespace log_stuff {

class LogTargetFile : public LogTarget {
 public:
  virtual void Write(LogMessageInfo const &log_message_info);
 private:
  file_stuff::FilePointer file_ptr_;
};

}

}

#endif // !SMALL_UTILITY_LOG_LOG_TARGET_FILE_H_
