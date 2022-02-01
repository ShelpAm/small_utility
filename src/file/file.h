#ifndef COMMAND_AND_DOMINATE_SRC_SMALL_UTILITY_FILE_FILE_H_
#define COMMAND_AND_DOMINATE_SRC_SMALL_UTILITY_FILE_FILE_H_

#include "file/file_forward.h"
#include <cstdio>

namespace small_utility {

namespace file_stuff {

class File{
 public:
  static FilePtr Create(char const *file_name = nullptr);
  File(char const *file_name);
  ~File();

  void Open(char const *file_name);
  void Append(char const *content) const;
  void PrintFormat(char const *format, ...) const;
  void Close();

 private:
  FILE* file_;
};

}

}

#endif // !COMMAND_AND_DOMINATE_SRC_SMALL_UTILITY_FILE_FILE_H_
