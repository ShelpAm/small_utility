// Copyright 2022 small_sheep_

#ifndef SMALL_UTILITY_FILE_FILE_H_
#define SMALL_UTILITY_FILE_FILE_H_

#include "small_utility/file/file_forward.h"
#include <cstdio>
#include <exception>
#include <map>

namespace small_utility {

namespace file_stuff {

// TODO(small_sheep_ 1178550325@qq.com) Please finish this rewrite.
class File {
 public:
  static void MakeFromFile(int const id, char const *const file_name,
                           bool const truncate);
  static std::map<int, File> &All() { return all_; }
  static File &FetchById(int const id);
  File(FILE *const file_pointer);
  ~File();

  void Write(char const *const str) const;

 private:
  void Close() const;

  static std::map<int, File> all_;
  FILE *const file_pointer_;
};

void MakeDirectory(char const *const path_name);
void Remove(char const *const path_name);

}  // namespace file_stuff

}  // namespace small_utility

#endif  // SMALL_UTILITY_FILE_FILE_H_
