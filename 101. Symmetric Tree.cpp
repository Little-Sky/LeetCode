// O(n) 
// Faster than 25%

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
public:
    bool isSymmetric(TreeNode* root) {
        return (!root || areSymmetric_(root->left, root->right));
    }
    
private:
    bool areSymmetric_ (TreeNode* le, TreeNode* ri) {
        if (!le && !ri) {
            return true;
        } else if (!le || !ri) {
            return false;
        } else {
            return (le->val == ri->val) && areSymmetric_(le->left, ri->right) && areSymmetric_(le->right, ri->left);
        }
    }
};
