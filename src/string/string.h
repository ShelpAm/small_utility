#ifndef SMALL_UTILITY_SRC_STRING_STRING_H_
#define SMALL_UTILITY_SRC_STRING_STRING_H_

namespace small_utility {

namespace string_stuff {

class string {
  using iterator = char *;
  using const_iterator = char const *;
 public:
  string(string const &rhs);
  string(char const *const rhs = "");
  string &operator=(string const &rhs);
  string &operator=(char const *const rhs);
  string &operator+=(char const c);
  string &operator+=(char const *const str);
  string &operator+=(string const &s);
  ~string();

  char const operator[](int const index) const;
  bool const operator==(string const &rhs) const;
  bool const operator==(char const *rhs) const;
  bool const operator!=(string const &rhs) const;
  bool const operator!=(char const *rhs) const;

  void swap(string &rhs);
  void push_back(char const c);
  void append(char const *const str);

  void reserve(int const size);
  void resize(int const size, char c = '\0');

  // brief:
  //  Insert a char $(c) at $(position). After calling this function,
  //  (*this)[position] will be 'c'.
  //
  // parameter:
  //  $(position) - the index of $(c) to be inserted
  //  $(c) - the char to be inserted
  void insert(char const c, int const position);
  void insert(char const *const str, int const position);

  // brief:
  //  Erase some characters, and fill them with the after characters.
  // parameter:
  //  $(position) - the index of place to be erased
  void erase(int const position, int const length);
  void clear();

  int const find(char const c, int const position = 0) const;
  int const find(char const *const str, int const position = 0) const;
  string sub_string_length(int const left, int const length) const;
  string sub_string_index(int const left, int const right) const;

  iterator begin() const { return data_; };
  iterator end() const { return data_ + size_; };

  char const *c_string() const { return data_; }
  char const *data() const { return data_; }
  int const length() const { return size_; }
  int const size() const { return size_; }
  int const capacity() const { return capacity_; }
 private:
  char *data_;
  int size_;
  int capacity_;
};

string operator+(string const &lhs, char const *rhs);
string operator+(char const *lhs, string const &rhs);

void print(string const &s);

}

}

#endif // !SMALL_UTILITY_SRC_STRING_STRING_H_
