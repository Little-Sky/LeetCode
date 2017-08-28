// O (n) Morris, three times constant time. O(1) memory
// Faster than 0.62%-78% [Facepalm]

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
    void recoverTree(TreeNode* root) {
        mx = INT_MIN;
        foundStart = foundEnd = false;
        
        // Morris inorder traversal
        TreeNode * cur = root;
        while (cur) {
            cout << cur->val << endl;
            if (cur->left) {
                TreeNode * predecessor = cur->left;
                while (predecessor->right && predecessor->right != cur) {
                    predecessor = predecessor->right;
                }
                if (!predecessor->right) {
                    predecessor->right = cur;
                    cur = cur->left;
                } else {
                    predecessor->right = NULL;
                    visitNode_(cur);
                    cur = cur->right;
                }
            } else {
                visitNode_(cur);
                cur = cur->right;
            }
        }
        swap (maxNode->val, minNode->val);
    }
    
private:
    TreeNode * maxNode, * minNode;
    int mx;
    bool foundStart, foundEnd;
    void visitNode_(TreeNode * cur) {
        if (!foundStart) {
            if (cur->val < mx) {
                foundStart = true;
                minNode = cur;
            } else {
                maxNode = cur;
                mx = cur->val;
            }
        } else {
            if (cur->val < mx) {
                minNode = cur;
            } else {
                foundEnd = true;
            }
        }
    }
};

//   0
//  /
// 1
