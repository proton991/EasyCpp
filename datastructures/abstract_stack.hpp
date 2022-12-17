#ifndef EASYCPP_ABSTRACT_STACK_HPP
#define EASYCPP_ABSTRACT_STACK_HPP

template <class T>
class AbstractStack {
public:
  virtual bool IsEmpty() const noexcept = 0;

  virtual size_t GetSize() const noexcept = 0;

  virtual bool Push(const T& val) = 0;

  virtual bool Pop() = 0;

  virtual const T& Top() const = 0;

  virtual void Clear() = 0;
};
#endif  //EASYCPP_ABSTRACT_STACK_HPP
