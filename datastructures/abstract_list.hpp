#ifndef EASYCPP_ABSTRACT_LIST_HPP
#define EASYCPP_ABSTRACT_LIST_HPP
#include "node.hpp"

template <class T>
class AbstractList {
public:
  virtual bool IsEmpty() const noexcept = 0;

  virtual size_t GetSize() const = 0;

  virtual bool Insert(size_t position, const T& value) = 0;

  virtual bool Remove(size_t position) = 0;

  virtual void Clear() = 0;

  virtual T Get(size_t position) = 0;

  virtual T Set(size_t position, const T& newValue) = 0;
};
#endif  //EASYCPP_ABSTRACT_LIST_HPP
