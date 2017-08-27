/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
// O(n) Morris method
// Faster than 1% - 1%
    
// The idea is to set the cur node be the right child of the predecessor. So that after you get their, move to right, you get back

public:
    vector<int> inorderTraversal (TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode* predecessor = cur->left;
                while (predecessor->right && predecessor->right != cur) {
                    predecessor = predecessor->right;
                }
                if (!predecessor->right) {
                    predecessor->right = cur;
                    cur = cur->left;
                } else {
                    predecessor->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            } else {
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
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
};
