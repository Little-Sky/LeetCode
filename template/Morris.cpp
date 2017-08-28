// Morris's algorithm: 
//   inorder traverse a binary search tree
// O(n) time complexity three iterations, O(1) space.

TreeNode * cur = root;
while (cur) {
  // if have left, then finds the predecessor (2 cases)
  if (cur->left) {
    TreeNode * predecessor = cur->left;
    while (predecessor->right && predecessor->right != cur) {
      predecessor = predecessor->right;
    }
    // case 1: the current node has not been visited
    if (!predecessor->right) {
      predecessor->right = cur;
      cur = cur->left;
    } 
    // case 2: the current node has already been visited
    else {
      predecessor->right = NULL;
      visitNode_(cur);
      cur = cur->right;
    }
  } else {
    visitNode_(cur);
    cur = cur->right;
  }
}
