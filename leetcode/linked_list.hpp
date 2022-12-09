#ifndef EASYCPP_LINKED_LIST_HPP
#define EASYCPP_LINKED_LIST_HPP

//  Definition for singly-linked list.
namespace lc {
struct ListNode {
  int val;
  ListNode* next;

  ListNode(int x) : val(x), next(NULL) {}
  friend ostream& operator << (ostream& out, const ListNode& node);
};

ostream &operator<<(ostream &out, const ListNode &node) {
  auto tmp = &node;
  while (tmp) {
    out << tmp->val << " ";
    tmp = tmp->next;
  }
  return out;
}
}


#endif //EASYCPP_LINKED_LIST_HPP
