#if !defined SMALL_UTILITY_FILE_FILE_H_
#define SMALL_UTILITY_FILE_FILE_H_

#include "file/file_forward.h"

#include <cstdio>

namespace small_utility {

namespace file_stuff {

class File {
 public:
  File(char const *const file_name, bool const truncate = false);
  ~File();

  // Prints something to file.
  int const Print(char const *const content) const;

 private:
  int const Open(char const *const file_name, bool const truncate);
  int const Close() const;

  FILE* file_ptr_;
};

} // namespace file_stuff

} // namespace small_utility

#endif // !SMALL_UTILITY_FILE_FILE_H_
