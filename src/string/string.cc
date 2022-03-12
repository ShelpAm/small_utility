#include "string/string.h"

#include <cstring>

#include "utility/small_utility.h"

namespace small_utility {

namespace string_stuff {

string::string(string const &rhs) : data_(nullptr) {
  string temp(rhs.data());
  swap(temp);
}

string::string(char const *const rhs) : size_(strlen(rhs)), capacity_(size_) {
  data_ = new char[size_ + 1];
  memcpy(data_, rhs, size_ + 1);
}

string &string::operator=(string const &rhs) {
  string temp(rhs.data());
  swap(temp);
  return *this;
}

string &string::operator=(char const *const rhs) {
  string temp(rhs);
  swap(temp);
  return *this;
}

string &string::operator+=(char const c) {
  push_back(c);
  return *this;
}

string &string::operator+=(char const *const str) {
  append(rhs);
 return *this;
}

string::~string() {
  delete[] data_;
}

char const string::operator[](int const index) const {
  assert(index >= 0 && index < size_);
  return data_[index];
}

bool const string::operator==(string const &rhs) const {
  return !strcmp(data_, rhs.data());
}

bool const string::operator==(char const *rhs) const {
  return !strcmp(data_, (rhs ? rhs : ""));
}

bool const string::operator!=(string const &rhs) const {
  return !(*this == rhs);
}

bool const string::operator!=(char const *rhs) const {
  return !(*this == rhs);
}

void string::swap(string &rhs) {
  small_utility::swap(data_, rhs.data_);
  small_utility::swap(size_, rhs.size_);
  small_utility::swap(capacity_, rhs.capacity_);
}

void string::push_back(char const c) {
  if (equal(size_, capacity_)) {
    reserve(capacity_ * 2);
  }
  data_[size_] = c;
  data_[size_ + 1] = '\0';
  ++size_;
}

void string::append(char const *const str) {
  const int str_length = strlen(str);
  const int adds_up_length = str_length + size_;
  if(adds_up_length >= capacity_) {
    reserve(adds_up_length * 2);
  }
  memcpy(data_ + size_, str, str_length);
  size_ += str_length;
}

string operator+(char const *lhs, string const &rhs) {
  return string(lhs) += rhs;
}

string operator+(string const &lhs, char const *rhs) {
  return string(lhs) += rhs;
}



string string::sub_string_from_to(int const left_index,
                                  int const right_index) const {
  if (left_index < 0 || right_index > size_
      || right_index < left_index) {
    return string();
  }
  printf("There is some problem in sub_string.");
  return string();
}

}

}
