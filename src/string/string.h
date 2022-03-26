#ifndef SMALL_UTILITY_SRC_STRING_STRING_H_
#define SMALL_UTILITY_SRC_STRING_STRING_H_

namespace small_utility {

namespace string_stuff {

class String {
  using Iterator = char *;
  using ConstIterator = char const *;
 public:
  String(char const *const rhs = "");
  String(String const &rhs);
  String &operator=(String rhs);
  String &operator=(char const *const rhs);
  String &operator+=(char const c);
  String &operator+=(char const *const str);
  String &operator+=(String const &string);
  ~String();

  char const operator[](int const index) const;

  void Swap(String &rhs);
  void PushBack(char const c);
  void Append(char const *const str);

  void Reserve(int const size);
  // Resizes the data_.
  //  If size is less than size_, the data from data_[size] will be truncated.
  //  If size is larger than size_, the extra room will be filled with c.
  void Resize(int const size, char c = '\0');

  //  Inserts a char $(c) at $(position). After calling this function,
  //  this->data_[position] will be 'c'.
  void Insert(char const c, int const position);
  void Insert(char const *const str, int const position);

  //  Erases some characters, and fill them with the after characters.
  // parameter:
  //  $(position) - the index of place to be Erased
  void Erase(int const position, int const length);
  void Clear();

  int const Find(char const c, int const position = 0) const;
  int const Find(char const *const str, int const position = 0) const;
  String SubStringLength(int const left, int const length) const;
  String SubStringIndex(int const left, int const right) const;

  Iterator Begin() const { return data_; };
  Iterator End() const { return data_ + size_; };

  char const *CStr() const { return data_; }
  char const *Data() const { return data_; }
  int const Length() const { return size_; }
  int const Size() const { return size_; }
  int const Capacity() const { return capacity_; }
 private:
  char *data_;
  int size_;
  int capacity_;
};

String operator+(String const &lhs, char const *rhs);
String operator+(char const *lhs, String const &rhs);
bool const operator<(char const *lhs, String const &rhs);
bool const operator<(String const &lhs, char const *const rhs);
bool const operator<(String const &lhs, String const &rhs);
bool const operator>(char const *lhs, String const &rhs);
bool const operator>(String const &lhs, char const *const rhs);
bool const operator>(String const &lhs, String const &rhs);
bool const operator==(char const *const lhs, String const &rhs);
bool const operator==(String const &lhs, char const *rhs);
bool const operator==(String const &lhs, String const &rhs);
bool const operator!=(char const *const lhs, String const &rhs);
bool const operator!=(String const &lhs, char const *rhs);
bool const operator!=(String const &lhs, String const &rhs);

void Print(String const &s);

}

}

#endif // !SMALL_UTILITY_SRC_STRING_STRING_H_
