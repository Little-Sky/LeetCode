// O(n)
// Faster than 26%


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> Q;
        if (root) {
            Q.push(root);
        }
        vector<vector<int>> res;
        while (!Q.empty()) {
            int n = Q.size();
            vector<int> row;
            for (int i=0; i<n; i++) {
                TreeNode * cur = Q.front();
                Q.pop();
                row.push_back(cur->val);
                if (cur->left)
                    Q.push(cur->left);
                if (cur->right)
                    Q.push(cur->right);
            }
            res.push_back(row);
        }
        for (int i=1; i<res.size(); i+=2) {
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
};
