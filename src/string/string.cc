#include "string/string.h"

#include <cassert>
#include <cstring>

namespace small_utility {

namespace string_stuff {

String::String() : data_(nullptr){
  CopyToThis(nullptr, 0);
}

String::String(String const &rhs) : data_(nullptr){
  CopyToThis(rhs.GetData(), rhs.GetLength());
}

String::String(char const *rhs) {
  if (!rhs) {
    CopyToThis(rhs, 0);
  } else {
    CopyToThis(rhs, strlen(rhs));
  }
}

String &String::operator=(String const &rhs) {
  CopyToThis(rhs.GetData(), rhs.GetLength());
  return *this;
}

String &String::operator=(char const *rhs) {
  if (!rhs) {
    CopyToThis(rhs, 0);
  } else {
    CopyToThis(rhs, strlen(rhs));
  }
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
  if (!rhs) {
    return !strcmp(data_, "");
  }
  return !strcmp(data_, rhs);
}

bool const String::operator!=(String const &rhs) const {
  return !(*this == rhs);
}

bool const String::operator!=(char const *rhs) const {
  return !(*this == rhs);
}

void String::CopyToThis(char const *data, int const length) {
if (data_ == data) {
    return;
  }
  if (data_) {
    delete[] data_;
  }
  data_ = new char[length + 1];
  if (!data) {
    data = "\0";
  }
  memcpy(data_, data, length + 1);
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
