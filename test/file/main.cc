#include "file/file.h"

#include <cstdio>

int main() {
  small_utility::file_stuff::FilePtr f1 =
    small_utility::file_stuff::File::Create("temporary_file1.tmp");
  small_utility::file_stuff::FilePtr f2 =
    small_utility::file_stuff::File::Create("correct_name2");

  f1->Append("content1");
  f1->PrintFormat("format1-%s", "format1");

  f2->Append("content2");
  f2->Close();
  f2->Close();

  printf("OK.\n");

  return 0;
}
