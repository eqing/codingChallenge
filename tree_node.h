#ifndef TREE_NODE_H
#define TREE_NODE_H

class TreeNode {
  public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

#endif