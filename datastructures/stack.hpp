#ifndef EASYCPP_STACK_HPP
#define EASYCPP_STACK_HPP

#include "abstract_stack.hpp"
#include "node.hpp"
#include <stdexcept>

template<typename T>
class Stack: public AbstractStack<T>
{
private:
  ListNode<T>* m_topPtr;    // Pointer to first node
  std::size_t m_size; // Current depth of the stack

public:
  /** Stack constructor
   *  creates an empty stack
   */
  Stack() : m_topPtr(nullptr), m_size(0) {}

  /** Stack destructor.
	* Must delete any allocated memory.
	*/
  virtual ~Stack() {
    Clear();
  }

  /** Returns the number of items on the stack.
	    @return The integer number of items on the stack. */
  size_t GetSize() const noexcept {
    return m_size;
  }

  /** Determines whether this stack is empty.
	    @return True if the stack has no items, or false if not. */
  bool IsEmpty() const noexcept {
    return m_size == 0;
  }

  /** Pushes a new entry onto the top of the stack.
		@post  If successful, newItem is on the top of the stack.
      @param newItem  The item (of datatype T) to be pushed on top of the stack.
		@return  True if insert was successful, or false if not. */
  bool Push(const T& newItem) {
    auto tmp = new ListNode<T>(newItem, m_topPtr);
    m_topPtr = tmp;
    tmp = nullptr;
    m_size++;
    return true;
  }

  /** Pops the top item off of the stack. The stack size is decreased by 1.
		@return  True if successful, or false otherwise. */
  bool Pop() {
    if (!IsEmpty()) {
      ListNode<T> *tmp = m_topPtr;
      m_topPtr = m_topPtr->GetNext();
      delete tmp;
      m_size--;
      return true;
    }
    return false;
  }

  /** Returns the top item off of the stack without removing it. The stack size
	    stays the same.
		@return  Item of T that was on the top of the stack. */
  const T& Top() const {
    if (!IsEmpty()) {
      return m_topPtr->GetItem();
    }
  }


  /** Deletes all entries on the stack.
	    @post  Stack contains no items, and the size of the stack is 0. */
  void Clear() {
    while (!IsEmpty()) {
      Pop();
    }
  }

}; // end Stack
#endif  //EASYCPP_STACK_HPP
