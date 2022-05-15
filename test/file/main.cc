#include "small_utility/file/file.h"
#include <cstdio>

using small_utility::file_stuff::File;

int main() {
  File::MakeFromFile(0, "temporary_file1.tmp", false);
  File::FetchById(0).Write("test123\n");
  return 0;}
