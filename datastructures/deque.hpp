#ifndef EASYCPP_DEQUE_HPP
#define EASYCPP_DEQUE_HPP
#include "abstract_deque.hpp"
#include <algorithm>
#define DEFAULT_CAPACITY 16
template <typename T>
class Deque : public AbstractDeque<T>
{
public:
  Deque() {
    items = new T[DEFAULT_CAPACITY];
    frontIndex = 0;
    backIndex = 0;
    capacity = DEFAULT_CAPACITY;
    size = 0;
  }

  Deque(Deque<T> &other) {
    frontIndex = other.frontIndex;
    backIndex = other.backIndex;
    size = other.size;
    capacity = other.capacity;
    items = new T[capacity];
    std::copy(other.items, other.items + other.capacity, items);
  }

  ~Deque() {
    delete[] items;
  }

  bool IsEmpty() const noexcept {
    return size == 0;
  }

  void PushFront(const T &item) {
    if (size == capacity - 1)
    {
      resize();
    }

    if (frontIndex == backIndex)
    {
      backIndex = (backIndex + 1 + capacity) % capacity;
    }
    items[frontIndex] = item;
    frontIndex = (frontIndex - 1 + capacity) % capacity;
    size++;
  }

  void PopFront() {
    if (!IsEmpty())
    {
      frontIndex = (frontIndex + 1 + capacity) % capacity;
      size--;
    }

  }

  const T &Front() const {
    return items[(frontIndex + 1 + capacity) % capacity];
  }

  void PushBack(const T &item) {
    if (size == capacity - 1)
    {
      resize();
    }

    if (frontIndex == backIndex)
    {
      frontIndex = (frontIndex - 1 + capacity) % capacity;
    }
    items[backIndex] = item;
    backIndex = (backIndex + 1 + capacity) % capacity;
    size++;
  }

  void PopBack() {
    if (!IsEmpty())
    {
      backIndex = (backIndex - 1 + capacity) % capacity;
      size--;
    }

  }

  const T &Back() const {
    return items[(backIndex - 1 + capacity) % capacity];
  }

private:
  T *items;
  unsigned int frontIndex;
  unsigned int backIndex;
  int size;
  int capacity;

  void resize() {
    T *temp = new T[capacity * 2];

    if (frontIndex >= backIndex)
    {
      for (int i = frontIndex; i < capacity; i++)
      {
        temp[capacity + i] = items[i];
      }
      for (int i = 0; i < frontIndex; i++)
      {
        temp[i] = items[i];
      }
      frontIndex = (frontIndex + capacity);
    }
    else
    {
      for (int i = backIndex; i < capacity; i++)
      {
        temp[capacity + i] = items[i];
      }
      for (int i = 0; i < backIndex; i++)
      {
        temp[i] = items[i];
      }
      backIndex = (backIndex + capacity);
    }

    capacity *= 2;

    delete[] items;
    items = nullptr;
    items = temp;
  }
};
#endif  //EASYCPP_DEQUE_HPP
