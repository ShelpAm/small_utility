// Copyright 2022 small_sheep_
//
#include "small_utility/file/file.h"
#include <cassert>
#include <cstring>
#include <exception>
#include <filesystem>

namespace small_utility {

namespace file_stuff {

void File::MakeFromFile(int const id, char const *const file_name,
                        bool const truncate) {
  FILE *const file_pointer = fopen(file_name, truncate ? "wb+" : "ab+");
  if (!file_pointer) {
    throw std::runtime_error("File unable to make from file.");
  }
  File::All().try_emplace(id, file_pointer);
}

File &File::FetchById(int const id) {
  if (!all_.contains(id)) {
    throw std::runtime_error("No such file.");
  }
  return all_.at(id);
}

File::File(FILE *const file_pointer) : file_pointer_(file_pointer) {}

File::~File() {
  Close();
}

void File::Write(char const *const str) const {
  fwrite(str, 1, strlen(str), file_pointer_);
}

void File::Close() const {
  fclose(file_pointer_);
}

std::map<int, File> File::all_;

void MakeDirectory(char const *const path_name) {
  std::filesystem::create_directories(path_name);
}

}  // namespace file_stuff

}  // namespace small_utility
