#include "string/string.h"

#include <cstdio>

int main() {
  small_utility::string_stuff::string s1;
  small_utility::string_stuff::string s2;

  s1 = "s1";
  s2 = "s2";
  s1 = s2;

  if (s1 != s2) {
    printf("This should not be printed, s1 != s2.\n");
  }

  s1 = "s1";
  s1 += s2;
  printf("%s-s1s2,%s-s1s2,%i-4,%i-4.\n",
         s1.c_string(), s1.data(), s1.size(), s1.size());

  s2 = "";
  printf("%s-,%s-,%i-0,%i-0\n", s2.c_string(), s2.data(), s2.size(), s2.size());

  s2 = nullptr;
  printf("%s-,%s-,%i-0,%i-0\n", s2.c_string(), s2.data(), s2.size(), s2.size());

  s1 = "0123456789";
  printf("%s-3456\n", s1.sub_string_from_to(3, 6).c_string());

  printf("OK.\n");

  return 0;
}
