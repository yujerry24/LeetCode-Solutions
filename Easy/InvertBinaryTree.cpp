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
    TreeNode* invertTree(TreeNode* root) {
        realInvert(root);
        return root;
    }
    
    void realInvert(TreeNode * root) {
        if(!root) {
            return;
        }
        TreeNode * temp = root->left;
        root->left=root->right;
        root->right=temp;
        realInvert(root->left);
        realInvert(root->right);
    }
};