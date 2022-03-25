#ifndef SMALL_UTILITY_LOG_LOG_TARGET_FILE_H_
#define SMALL_UTILITY_LOG_LOG_TARGET_FILE_H_

#include "file/file.h"
#include "log/log_target.h"

namespace small_utility {

namespace log_stuff {

class LogTargetFile : public LogTarget {
 public:
  virtual void Write(string_stuff::String const &log_message);
 private:
  file_stuff::FilePointer file_pointer_;
};

}

}

#endif // !SMALL_UTILITY_LOG_LOG_TARGET_FILE_H_
