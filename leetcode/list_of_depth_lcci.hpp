#ifndef EASYCPP_LIST_OF_DEPTH_LCCI_HPP
#define EASYCPP_LIST_OF_DEPTH_LCCI_HPP

#include <vector>
#include <queue>
#include "tree.hpp"
#include "linked_list.hpp"

using namespace std;
namespace lc {
class lodSolution {
public:
  vector<ListNode*> listOfDepth(TreeNode* tree) {
    queue<TreeNode*> q;
    q.push(tree);
    vector<ListNode*> ans;
    while (!q.empty()) {
      int n = q.size();
      ListNode* currentLevel = new ListNode(-1);
      ListNode* ptr = currentLevel;
      for (int i = 0; i < n; ++i) {
        auto node = q.front();
        q.pop();
        if (node != nullptr) {
          ListNode* tmp = new ListNode(node->val);
          ptr->next = tmp;
          ptr = ptr->next;
          if (node->left != nullptr) q.push(node->left);
          if (node->right != nullptr) q.push(node->right);
        }
      }
      if (ptr != currentLevel) {
        ans.push_back(currentLevel->next);
      }
    }
    return ans;
  }
};
}

#endif //EASYCPP_LIST_OF_DEPTH_LCCI_HPP
