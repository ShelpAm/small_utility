#include "string/string.h"

#include <cstdio>

int main() {
  small_utility::string_stuff::String s1;
  small_utility::string_stuff::String s2;

  s1 = "s1";
  s2 = "s2";
  s1 = s2;

  if (s1 != s2) {
    printf("This should not be printed, s1 != s2.\n");
  }

  s1 = "s1";
  s1 += s2;
  printf("%s-s1s2,%s-s1s2,%i-4,%i-4.\n",
         s1.ToCString(), s1.GetData(), s1.GetLength(), s1.GetSize());

  s2 = "";
  printf("%s-,%s-,%i-0,%i-0\n", s2.ToCString(), s2.GetData(), s2.GetLength(), s2.GetSize());

  s2 = nullptr;
  printf("%s-,%s-,%i-0,%i-0\n", s2.ToCString(), s2.GetData(), s2.GetLength(), s2.GetSize());

  printf("OK.\n");

  return 0;
}
