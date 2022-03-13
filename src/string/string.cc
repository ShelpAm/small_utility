#include "string/string.h"

#include <cassert>
#include <cstdio>
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
  append(str);
  return *this;
}

string &string::operator+=(string const &s) {
  append(s.data());
  return *this;
}

string::~string() {
  delete[] data_;
}

char const string::operator[](int const index) const {
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

void string::reserve(int const size) {
  if (size <= size_) {
    return;
  }
  char *new_data = new char[size + 1];
  memcpy(new_data, data_, size_);
  delete[] data_;
  data_ = new_data;
  capacity_ = size;
}

void string::resize(int const size, char c) {
  if (size < size_) {
    data_[size] = '\0';
  } else {
    if (size > capacity_) {
      reserve(size);
    }
    for (int i = 0; i != size; ++i) {
      data_[i] = c;
    }
    data_[size] = '\0';
  }
  size_ = size;
}

void string::insert(char const c, int const position) {
  assert(position >= 0 && position <= size_);
  if (equal(size_, capacity_)) {
    reserve(capacity_ * 2);
  }
  for (int i = size_ + 1; i != position; --i) {
    data_[i] = data_[i - 1];
  }
  data_[position] = c;
  ++size_;
}

void string::insert(char const *const str, int const position) {

}

void string::erase(int const position, int const length) {
}

void string::clear() {
  data_[0] = '\0';
  size_ = 0;
}

int const string::find(char const c, int const position) const {
  assert(position >= 0 && position <= size_);
  for (int i = position; i != size_; ++i) {
    if (equal(data_[i], c)) {
      return i;
    }
  }
  return -1;
}

int const string::find(char const *const str, int const position) const {

}

string string::sub_string_length(int const left, int const length) const {
  assert(left >= 0 && length > 0 && left + length <= size_);
  char sub_str[length + 1];
  memcpy(sub_str, data_ + left, length);
  sub_str[length] = '\0';
  return string(sub_str);
}

string string::sub_string_index(int const left, int const right) const {
  return sub_string_length(left, right - left + 1);
}

string operator+(char const *lhs, string const &rhs) {
  return string(lhs) += rhs;
}

string operator+(string const &lhs, char const *rhs) {
  return string(lhs) += rhs;
}

void print(string const &s) {
  printf("The data of string:%s", s.data());
}

}

}
