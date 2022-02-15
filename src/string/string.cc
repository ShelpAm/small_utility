#include "string/string.h"

#include <cassert>
#include <cstring>
#include <sstream>

namespace small_utility {

namespace string_stuff {

String::String() : data_(nullptr), length_(0) {
  CopyToThis(nullptr, 0);
}

String::String(String const &rhs) : data_(nullptr), length_(0) {
  CopyToThis(rhs.GetData(), rhs.GetLength());
}

String::String(char const *rhs) : data_(nullptr), length_(0) {
  CopyToThis(rhs, (rhs ? strlen(rhs) : 0));
}

String &String::operator=(String const &rhs) {
  CopyToThis(rhs.GetData(), rhs.GetLength());
  return *this;
}

String &String::operator=(char const *rhs) {
  CopyToThis(rhs, (rhs ? strlen(rhs) : 0));
  return *this;
}

String &String::operator+=(String const &rhs) {
  char *origin_data = data_;
  int const objective_length = length_ + rhs.GetLength();
  data_ = new char[objective_length + 1];
  memcpy(data_, origin_data, length_);
  memcpy(data_ + length_, rhs.GetData(), rhs.GetLength());
  length_ = objective_length;
  delete[] origin_data;
  return *this;
}

String &String::operator+=(char const *rhs) {
  if (!rhs) {
    return *this;
  }
  char *origin_data = data_;
  int const rhs_length = strlen(rhs);
  int const objective_length = length_ + rhs_length;
  data_ = new char[objective_length + 1];
  memcpy(data_, origin_data, length_);
  memcpy(data_ + length_, rhs, rhs_length);
  length_ = objective_length;
  delete[] origin_data;
  return *this;
}

String::~String() {
  delete[] data_;
}

char const String::operator[](int const index) const {
  assert(index >= 0 && index < length_);
  return data_[index];
}
bool const String::operator==(String const &rhs) const {
  return !strcmp(data_, rhs.GetData());
}

bool const String::operator==(char const *rhs) const {
  return !strcmp(data_, (rhs ? rhs : ""));
}

bool const String::operator!=(String const &rhs) const {
  return !(*this == rhs);
}

bool const String::operator!=(char const *rhs) const {
  return !(*this == rhs);
}

String String::sub_string(int const left_index, int const right_index) const {
  assert(left_index >= 0);
  assert(right_index <= this->GetLength());
  assert(right_index >= left_index);
  int const terminal_string_length = right_index - left_index + 1;
  char *terminal_data = new char[terminal_string_length + 1];
  // the "+1" is for '\0'.
  memcpy(terminal_data, this->GetData() + left_index, terminal_string_length);
  memcpy(terminal_data + terminal_string_length , "\0", 1);
  return String(terminal_data);
}

void String::CopyToThis(char const *data, int const length) {
  if (data_ == data) {
    return;
  }
  if (data_) {
    delete[] data_;
  }
  data_ = new char[length + 1];
  memcpy(data_, (data ? data : "\0"), length + 1);
  length_ = length;
}

String operator+(char const *lhs, String const &rhs) {
  return String(lhs) += rhs;
}

String operator+(String const &lhs, char const *rhs) {
  return String(lhs) += rhs;
}

}

}
