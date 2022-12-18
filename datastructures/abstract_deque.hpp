#ifndef EASYCPP_ABSTRACT_DEQUE_HPP
#define EASYCPP_ABSTRACT_DEQUE_HPP

template <class T>
class AbstractDeque {

  virtual bool IsEmpty() const noexcept = 0;

  virtual void PushFront(const T& val) = 0;

  virtual void PopFront() = 0;

  virtual const T& Front() const = 0;

  virtual void PushBack(const T& val) = 0;

  virtual void PopBack() = 0;

  virtual const T& Back() const = 0;
};
#endif  //EASYCPP_ABSTRACT_DEQUE_HPP
