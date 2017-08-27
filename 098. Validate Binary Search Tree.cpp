// O(n)
// Faster than 41% - 41%

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
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        } else {
            pair<int, int> extreme = isValidBST_ (root);
            return extreme.first <= extreme.second;
        }
    }
    
private:
    pair<int, int> isValidBST_ (TreeNode* cur) {
        pair<int, int> extreme = make_pair(cur->val, cur->val);
        if (cur->left) {
            pair<int, int> left = isValidBST_ (cur->left);
            if (left.first > left.second ||left.second >= extreme.first) {
                return make_pair(INT_MAX, INT_MIN);
            } else {
                extreme.first = left.first;
            }
        }
        if (cur->right) {
            pair<int, int> right = isValidBST_ (cur->right);
            if (right.first > right.second || right.first <= extreme.second) {
                return make_pair(INT_MAX, INT_MIN);
            } else {
                extreme.second = right.second;
            }
        }
        return extreme;
    }
};
