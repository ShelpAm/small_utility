#include "string/string.h"

#include <cstdio>
#include <vector>

int main() {
  std::vector<int> error_codes;
  small_utility::string_stuff::string s1("test");
  small_utility::string_stuff::string s2(s1);
  s2 = s2;
  if (s1 != s2) {
    error_codes.push_back(1);
  }
  if (s2 != s2) {
    error_codes.push_back(2);
  }
  s1 += s2;
  s1 += s2[0];
  if (s1 != "testtestt") {
    error_codes.push_back(3);
  }
  if (s1.size() != 9) {
    error_codes.push_back(4);
  }
  small_utility::string_stuff::string temp(s1);
  s1.swap(s2);
  if (s2 != temp) {
    error_codes.push_back(5);
  }
  s1.swap(s2);
  if (s1 != temp) {
    error_codes.push_back(6);
  }
  s1.reserve(20);
  if (s1.capacity() != 20) {
    error_codes.push_back(7);
  }
  s1.resize(1, 'i');
  if (s1 != small_utility::string_stuff::string("t")) {
    error_codes.push_back(8);
  }
  s1.insert('o', 1);
  if (s1 != small_utility::string_stuff::string("to")) {
    error_codes.push_back(9);
  }
  s1.insert("pq", 2);
  if (s1 != "topq") {
    error_codes.push_back(10);
  }
  s1.erase(1, 2);
  if (s1 != "tq") {
    error_codes.push_back(11);
  }
  s1.clear();
  if (s1.find('i') != -1) {
    error_codes.push_back(12);
  }
  s1 = "0123";
  temp = s1.sub_string_length(0, 4);
  if (s1 != temp) {
    error_codes.push_back(13);
  }

  printf("string test OK.\n");
  if (!error_codes.empty()) {
    for (auto const i : error_codes) {
      printf("%i ", i);
    }
    printf("\n");
    return -1;
  }
  return 0;
}
