#include "file/file.h"

#include <cassert>
#include <cstdarg>
#include <cstring>

namespace small_utility {

namespace file_stuff {

FilePtr File::Create(char const *file_name) {
  assert(file_name);
  assert(strcmp(file_name, ""));
  return std::make_shared<File>(file_name);
}

File::File(char const *file_name) : file_(nullptr) {
  Open(file_name);
}

File::~File() {
  Close();
}

void File::Open(char const *file_name) {
  Close();
  file_ = fopen(file_name, "ab");
  if (file_ == nullptr) {
    printf("[Warning::File::Open] Failed to open file %s.\n", file_name);
  }
}

void File::Append(char const *content) const {
  unsigned int size = strlen(content);
  if (fwrite(content, 1, size, file_) != size) {
    printf("[Warning] Failed to append the content of %s.\n", content);
  }
}

void File::PrintFormat(char const *format, ...) const {
  va_list args;
  va_start(args, format);
  vfprintf(file_, format, args);
  va_end(args);
  return;
}

void File::Close() {
  if (!file_) {
    return;
  }
  if (fclose(file_) != 0) {
    printf("[Warning] Failed to close the file.\n");
  }
  file_ = nullptr;
}

}

}
