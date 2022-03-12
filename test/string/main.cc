#include "string/string.h"

#include <cstdio>

int main() {
  small_utility::string_stuff::string s1;
  small_utility::string_stuff::string s2;

  s1 = "s1";
  s2 = "s2";
  s1 = s2;

  if (s1 != s2) {
    printf("Error0\n");
  }

  s1 = "s1";
  s1 += s2;
  if (s1 != "s1s2" || s1.size() != 4) {
    printf("Error1\n");
  }

  s2 = "";
  if (s2 != "", s2.size() != 0) {
    printf("Error2\n");
  }

  s1 = "0123456789";
  if (s1.sub_string(3, 4) != "3456") {
    printf("Error3\n");
  }

  printf("string test OK.\n");

  return 0;
}
