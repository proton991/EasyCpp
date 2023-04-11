#pragma once
#include "linked_list.hpp"
namespace lc {
class ReverseList {
public:
  ListNode* reverseList(ListNode* head) {
    auto curr      = head;
    ListNode* prev = nullptr;
    while (curr) {
      auto next  = curr->next;
      curr->next = prev;
      prev       = curr;
      curr       = next;
    }
    return prev;
  }

  ListNode* reverseListRecur(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode newHead = reverseListRecur(head->next);
    head->next->next = head;
    head->next       = nullptr;
    return head;
  }
};
}  // namespace lc
