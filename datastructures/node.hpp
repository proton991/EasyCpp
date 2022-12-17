#ifndef EASYCPP_NODE_HPP
#define EASYCPP_NODE_HPP

template <class T>
class ListNode {
public:
  ListNode() = default;

  explicit ListNode(const T& val) : m_item(val), m_next(nullptr) {}

  ListNode(const T& val, ListNode<T>* next) : m_item(val), m_next(next) {}

  void SetNext(ListNode<T>* next) { m_next = next; }

  T GetItem() const { return m_item; }

  ListNode<T>* GetNext() const { return m_next; }

private:
  T m_item;
  ListNode<T>* m_next;
};

template <class T>
class TreeNode {
public:
  TreeNode() = default;

  explicit TreeNode(const T& val) : m_val(val), m_left(nullptr), m_right(nullptr) {}

  TreeNode(const T& val, TreeNode<T>* left, TreeNode<T>* right)
      : m_val(val), m_left(left), m_right(right) {}

  void SetLeft(TreeNode<T>* node) { m_left = node; }

  void SetRight(TreeNode<T>* node) { m_right = node; }

  TreeNode<T>* GetLeft() const { return m_left; }

  TreeNode<T>* GetRight() const { return m_right; }

  T GetValue() const { return m_val; }

private:
  T m_val;
  TreeNode<T>* m_left;
  TreeNode<T>* m_right;
};
#endif  //EASYCPP_NODE_HPP
