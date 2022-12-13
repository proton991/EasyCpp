#ifndef EASYCPP_TREE_HPP
#define EASYCPP_TREE_HPP

namespace lc {
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
}


#endif //EASYCPP_TREE_HPP
