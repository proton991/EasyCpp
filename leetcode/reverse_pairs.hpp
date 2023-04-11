#pragma once
#include "linked_list.hpp"
namespace lc {
class ReversePairs {
public:
  ListNode* swapPairs(ListNode* head) {
    auto dummy_head  = new ListNode(-1);
    dummy_head->next = head;
    auto curr        = dummy_head;
    while (curr->next && curr->next->next) {
      auto tmp1              = curr->next;
      auto tmp2              = curr->next->next->next;
      curr->next             = tmp1->next;
      curr->next->next       = tmp1;
      curr->next->next->next = tmp2;

      curr = curr->next->next;
    }
    return dummy_head->next;
  }
};
}  // namespace lc