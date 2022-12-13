#ifndef EASYCPP_SORTED_STACK_LCCI_HPP
#define EASYCPP_SORTED_STACK_LCCI_HPP

#include <stack>

using namespace std;
namespace lc {
class SortedStack {
public:
  SortedStack() {

  }

  void push(int val) {
    if (m_stack.empty()) {
      m_stack.push(val);
    } else {
      while (!m_stack.empty() && m_stack.top() < val) {
        m_auxStack.push(m_stack.top());
        m_stack.pop();
      }
      m_stack.push(val);
      while (!m_auxStack.empty()) {
        m_stack.push(m_auxStack.top());
        m_auxStack.pop();
      }
    }
  }

  void pop() {
    if (!m_stack.empty())
      m_stack.pop();
  }

  int peek() {
    if (!m_stack.empty())
      return m_stack.top();
    else
      return -1;
  }

  bool isEmpty() {
    return m_stack.empty();
  }

private:
  stack<int> m_stack;
  stack<int> m_auxStack;
};

}
#endif //EASYCPP_SORTED_STACK_LCCI_HPP
