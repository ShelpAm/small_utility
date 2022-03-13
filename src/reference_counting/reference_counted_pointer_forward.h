#if !defined SMALL_UTILITY_REFERENCE_COUNTING_REFERENCE_COUNTED_POINTER_H_
#define SMALL_UTILITY_REFERENCE_COUNTING_REFERENCE_COUNTED_POINTER_H_

template<typename type>
class referece_counted_pointer<type> {
 public:

 private:
  reference_holder<type> *reference_holder_;
};

#endif // !SMALL_UTILITY_REFERENCE_COUNTING_REFERENCE_COUNTED_POINTER_H_
