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
  void insert(int const position, char const c);
  void insert(int const position, char const *const str);
  void erase(int const position, int const length);
  void clear();

  int const find(char const c) const;
  int const find(char const *const str) const;
  int const find_from_to(char const c, int const left_index,
                         int const right_index) const;
  int const find_from_to(char const *const str, int const left_index,
                         int const right_index) const;
  string sub_string_from_to(int const left_index, int const right_index) const;

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

}

}

#endif // !SMALL_UTILITY_SRC_STRING_STRING_H_
