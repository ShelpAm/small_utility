#if !defined SMALL_UTILITY_REFERENCE_COUNTING_REFERENCE_COUNTED_POINTER_H_
#define SMALL_UTILITY_REFERENCE_COUNTING_REFERENCE_COUNTED_POINTER_H_

template<typename type>
class referece_counted_pointer<type> {
 public:
  referece_counted_pointer<type>(reference_holder<type> *reference_holder);
  referece_counted_pointer<type>(
      referece_counted_pointer<type> const &referece_counted_pointer);

  referece_counted_pointer<type> &operator=(
      referece_counted_pointer<type> const &referece_counted_pointer);
  referece_counted_pointer<type> &operator=(
      referece_counted_pointer<type> const &referece_counted_pointer);

  ~referece_counted_pointer<type>();

 private:
  reference_holder<type> *reference_holder_;
};

#endif // !SMALL_UTILITY_REFERENCE_COUNTING_REFERENCE_COUNTED_POINTER_H_
