#include "string/string.h"

#include <cassert>
#include <cstdio>
#include <cstring>

#include "utility/utility.h"

namespace small_utility {

namespace string_stuff {

String::String(String const &rhs) : data_(nullptr) {
  String temp(rhs.Data());
  Swap(temp);
}

String::String(char const *const rhs) : size_(strlen(rhs)), capacity_(size_) {
  data_ = new char[size_ + 1];
  memcpy(data_, rhs, size_ + 1);
}

String &String::operator=(String const &rhs) {
  String temp(rhs.Data());
  Swap(temp);
  return *this;
}

String &String::operator=(char const *const rhs) {
  String temp(rhs);
  Swap(temp);
  return *this;
}

String &String::operator+=(char const c) {
  PushBack(c);
  return *this;
}

String &String::operator+=(char const *const str) {
  Append(str);
  return *this;
}

String &String::operator+=(String const &s) {
  Append(s.Data());
  return *this;
}

String::~String() {
  delete[] data_;
}

char const String::operator[](int const index) const {
  assert(index >= 0); assert(index < size_);
  return data_[index];
}

void String::Swap(String &rhs) {
  utility::Swap(data_, rhs.data_);
  utility::Swap(size_, rhs.size_);
  utility::Swap(capacity_, rhs.capacity_);
}

void String::PushBack(char const c) {
  if (utility::Equal(size_, capacity_)) {
    Reserve(capacity_ ? capacity_ * 2 : 1);
  }
  data_[size_] = c;
  data_[size_ + 1] = '\0';
  ++size_;
}

void String::Append(char const *const str) {
  const int str_length = strlen(str);
  const int adds_up_length = str_length + size_;
  if(adds_up_length >= capacity_) {
    Reserve(adds_up_length * 2);
  }
  memcpy(data_ + size_, str, str_length);
  size_ += str_length;
}

void String::Reserve(int const size) {
  if (size <= size_) {
    return;
  }
  char *new_data = new char[size_ + 1];
  memcpy(new_data, data_, size_);
  delete[] data_;
  data_ = new_data;
  capacity_ = size;
}

void String::Resize(int const size, char c) {
  if (size < size_) {
    data_[size] = '\0';
  } else {
    if (size > capacity_) {
      Reserve(size);
    }
    for (int i = 0; i != size; ++i) {
      data_[i] = c;
    }
    data_[size] = '\0';
  }
  size_ = size_;
}

void String::Insert(char const c, int const position) {
  assert(position >= 0 && position <= size_);
  if (utility::Equal(size_, capacity_)) {
    Reserve(capacity_ * 2);
  }
  for (int i = size_ + 1; i != position; --i) {
    data_[i] = data_[i - 1];
  }
  data_[position] = c;
  ++size_;
}

void String::Insert(char const *const str, int const position) {
  assert(position >= 0 && position <= size_);
  int const str_length = strlen(str);
  if (size_ + str_length > capacity_) {
    Reserve(size_ + str_length);
  }
  // make room for Insertee.
  for (int i = size_; i != position - 1; --i) {
    data_[i + str_length] = data_[i];
  }
  memcpy(data_ + position, str, str_length);
  size_ += str_length;
}

void String::Erase(int const position, int const length) {
  assert(position >= 0 && position <= size_);
  assert(length >= 0);
  if (length >= size_ - position + 1) {
    data_[position] = '\0';
    size_ = position;
  } else {
    memcpy(data_ + position, data_ + position + length, size_ - position + 1);
    size_ -= length;
  }
}

void String::Clear() {
  data_[0] = '\0';
  size_ = 0;
}

int const String::Find(char const c, int const position) const {
  assert(position >= 0 && position <= size_);
  for (int i = position; i != size_; ++i) {
    if (utility::Equal(data_[i], c)) {
      return i;
    }
  }
  return -1;
}

int const String::Find(char const *const str, int const position) const {
  assert(position >= 0 && position <= size_);
  char const *const sub_str = strstr(data_ + position, str);
  if (sub_str) {
    return sub_str - data_;
  } else {
    return -1;
  }
}

String String::SubStringLength(int const left, int const length) const {
  assert(left >= 0 && length > 0 && left + length - 1 <= size_);
  char sub_str[length + 1];
  memcpy(sub_str, data_ + left, length);
  sub_str[length] = '\0';
  return String(sub_str);
}

String String::SubStringIndex(int const left, int const right) const {
  return SubStringLength(left, right - left + 1);
}

String operator+(char const *lhs, String const &rhs) {
  return String(lhs) += rhs;
}

String operator+(String const &lhs, char const *rhs) {
  return String(lhs) += rhs;
}

bool const operator<(char const *lhs, String const &rhs) {
  return strcmp(lhs, rhs.Data()) < 0;
}

bool const operator<(String const &lhs, char const *const rhs) {
  return strcmp(lhs.Data(), rhs) < 0;
}

bool const operator<(String const &lhs, String const &rhs) {
  return strcmp(lhs.Data(), rhs.Data()) < 0;
}

bool const operator>(char const *lhs, String const &rhs) {
  return strcmp(lhs, rhs.Data()) > 0;
}

bool const operator>(String const &lhs, char const *const rhs) {
  return strcmp(lhs.Data(), rhs) > 0;
}

bool const operator>(String const &lhs, String const &rhs) {
  return strcmp(lhs.Data(), rhs.Data()) > 0;
}

bool const operator==(char const *lhs, String const &rhs) {
  return !strcmp(lhs, rhs.Data());
}

bool const operator==(String const &lhs, char const *const rhs) {
  return !strcmp(lhs.Data(), rhs);
}

bool const operator==(String const &lhs, String const &rhs) {
  return !strcmp(lhs.Data(), rhs.Data());
}

bool const operator!=(char const *lhs, String const &rhs) {
  return strcmp(lhs, rhs.Data());
}

bool const operator!=(String const &lhs, char const *const rhs) {
  return strcmp(lhs.Data(), rhs);
}

bool const operator!=(String const &lhs, String const &rhs) {
  return strcmp(lhs.Data(), rhs.Data());
}

void Print(String const &s) {
  printf("The data_ of string:%s", s.Data());
}

}

}
