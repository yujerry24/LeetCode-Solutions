/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//September 4th, 2019
//Recursive Solution:
//Used a pointer to a vector that would keep track of the all the inserted values 
//One of the easier medium questions
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> * storage = new vector<int>;
        vector<int> actual;
        storage->clear();
        inorderTraversalHelper(root, storage);
        for (int i=0; i<storage->size(); i++) {
            actual.push_back(storage->at(i));
        }
        
        return actual;
    }
    
    void inorderTraversalHelper(TreeNode * root, vector<int> * list) {
        if(root == nullptr) {
            return;
        }
        inorderTraversalHelper(root->left, list);
        list->push_back(root->val);
        inorderTraversalHelper(root->right, list);
        
    }
};