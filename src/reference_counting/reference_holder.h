#if !defined SMALL_UTILITY_REFERENCE_COUNTING_REFERENCE_HOLDER_H_
#define SMALL_UTILITY_REFERENCE_COUNTING_REFERENCE_HOLDER_H_

template<typename type>
class reference_holder<type> {
 public:

 private:
 type *referece_;
 int reference_count_;
};

#endif // !SMALL_UTILITY_REFERENCE_COUNTING_REFERENCE_HOLDER_H_
