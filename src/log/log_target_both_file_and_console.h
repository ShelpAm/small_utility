#ifdef SMALL_UTILITY_LOG_LOG_TARGET_BOTH_FILE_AND_CONSOLE_H_
#define SMALL_UTILITY_LOG_LOG_TARGET_BOTH_FILE_AND_CONSOLE_H_

#include "log/log_target_console.h"
#include "log/log_target_file.h"

namespace small_utility {

namespace log_stuff {

class LogTargetBothFileAndConsole
    : public LogTargetFile, public LogTargetConsole {
 public:
  virtual void Write(LogMessageInfo const &);
};

}

}

#endif // !SMALL_UTILITY_LOG_LOG_TARGET_BOTH_FILE_AND_CONSOLE_H_
