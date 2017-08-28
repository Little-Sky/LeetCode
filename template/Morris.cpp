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

// // O(n) iterative method
// // Faster than 1% - 1%

// // The idea is to view a tree as a group of parallel "anti-diagonal" direction chains, explore each of them in order
// // When exploring, use the current pointer goes left, when reaches end, goes back, write down the number, and tries right
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         stack<TreeNode *> nodeStack;
//         TreeNode * cur = root;
//         while (cur || nodeStack.size()) {
//             while (cur) {
//                 nodeStack.push(cur);
//                 cur = cur->left;
//             }
//             cur = nodeStack.top();
//             nodeStack.pop();
//             res.push_back(cur->val);
//             cur = cur->right;
//         }
//         return res;
//     }


// // O(n) Trivial recursive solution
// // Faster than 70%
    
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         inorderTraversal_(root, res);
//         return res;
//     }
// private:
//     void inorderTraversal_(TreeNode* cur, vector<int> & res) {
//         if (!cur) {
//             return;
//         }
//         inorderTraversal_(cur->left, res);
//         res.push_back(cur->val);
//         inorderTraversal_(cur->right, res);
//     }
