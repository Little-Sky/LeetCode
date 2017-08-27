// O(n)
// Faster than 36%-36%


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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*> ();
        }
        return generateSubTrees_(n, 0);
    }
    
private:
    vector<TreeNode*> generateSubTrees_(int n, int base) {
        vector<TreeNode*> res;
        if (n == 0) {
            res.push_back(NULL);
        } else if (n == 1) {
            res.push_back(new TreeNode(base+1));
        } else {
            // current node value = i
            for (int i=1; i<=n; i++) {
                vector<TreeNode*> leftChilds = generateSubTrees_(i-1, base);
                vector<TreeNode*> rightChilds = generateSubTrees_(n-i, base+i);
                for (TreeNode* leftChild : leftChilds) {
                    for (TreeNode* rightChild : rightChilds) {
                        TreeNode * curNode = new TreeNode(i + base);
                        curNode->left = leftChild;
                        curNode->right = rightChild;
                        res.push_back(curNode);
                    }
                }
            }
        }
        return res;
    }
};
