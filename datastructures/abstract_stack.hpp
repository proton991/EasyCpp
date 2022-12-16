#ifndef EASYCPP_ABSTRACT_STACK_HPP
#define EASYCPP_ABSTRACT_STACK_HPP

template <class T>
class AbstractStack {
public:
  virtual size_t IsEmpty() const noexcept = 0;

  virtual bool Push(const T& val) = 0;

  virtual bool Pop() = 0;

  const T& Top() = 0;
};
#endif  //EASYCPP_ABSTRACT_STACK_HPP
