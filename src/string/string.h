#ifndef SMALL_UTILITY_SRC_STRING_STRING_H_
#define SMALL_UTILITY_SRC_STRING_STRING_H_

namespace small_utility {

namespace string_stuff {

class String {
 public:
  String();
  String(String const &rhs);
  String(char const *rhs);
  String &operator=(String const &rhs);
  String &operator=(char const *rhs);
  String &operator+=(String const &rhs);
  String &operator+=(char const *rhs);
  ~String();

  char const operator[](int const index) const;
  bool const operator==(String const &rhs) const;
  bool const operator==(char const *rhs) const;
  bool const operator!=(String const &rhs) const;
  bool const operator!=(char const *rhs) const;

  char const *ToCString() const { return data_; }
  char const *GetData() const { return data_; }
  int const GetLength() const { return length_; }
  int const GetSize() const { return 1 * length_; }
 private:
  void CopyToThis(char const *data, int const length);

  char *data_;
  int length_;
};

String operator+(String const &lhs, char const *rhs);
String operator+(char const *lhs, String const &rhs);

}

}

#endif // !SMALL_UTILITY_SRC_STRING_STRING_H_
