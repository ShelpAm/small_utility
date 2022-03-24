#include "file/file.h"

#include <cassert>
#include <cstring>

namespace small_utility {

namespace file_stuff {

File::File(char const *const file_name, bool const truncate) {
  if (Open(file_name, truncate)) {
    assert(0);
  }
}

File::~File() {
  if (Close()) {
    assert(0);
  }
}

int const File::Print(char const *const content) const {
  if (!file_ptr_) { return 1; }
  if (!content) { return 3; }
  fwrite(content, 1, strlen(content), file_ptr_);
  return 0;
}

int const File::Open(char const *const file_name, bool const truncate) {
  char *str;
  if (truncate) { str = "wb+"; }
  else { str = "ab+"; }

  file_ptr_ = fopen(file_name, str);
  if (!file_ptr_) { return 1; }
  return 0;
}

int const File::Close() const {
  if (!file_ptr_) { return 1; }
  if (!fclose(file_ptr_)) { return 2; }
}

}

}
