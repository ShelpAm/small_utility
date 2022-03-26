#include <cstdio>

#include "utility/utility.h"

using namespace small_utility;

int main() {
  FILE *file_ptr;
  file_ptr = utility::Popen("./build/test-file", "r");
  if (file_ptr) { utility::Pclose(file_ptr); }
  file_ptr = utility::Popen("./build/test-string", "r");
  if (file_ptr) { utility::Pclose(file_ptr); }
  file_ptr = utility::Popen("./build/test-log", "r");
  if (file_ptr) { utility::Pclose(file_ptr); }
  file_ptr = utility::Popen("./build/test-utility", "r");
  if (file_ptr) { utility::Pclose(file_ptr); }
  file_ptr = utility::Popen("./build/test-reference_counting", "r");
  if (file_ptr) { utility::Pclose(file_ptr); }

  return 0;
}
