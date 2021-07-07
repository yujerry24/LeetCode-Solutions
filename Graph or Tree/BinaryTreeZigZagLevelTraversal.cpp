/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> results;
        vector<int> temp;
        vector<TreeNode*> queue;
        boolean is_order_left = true;
        queue.push_back(root);
        queue.push_back(NULL);
        while(!queue.empty()) {
            TreeNode * cur = queue.at(0);
            queue.erase(queue.begin());
            if (cur != NULL) {
                temp.push_back(cur->val);
                if (cur->right) {
                    queue.push_back(cur->right);
                }
                if (cur->left) {
                    queue.push_back(cur->left);
                }
            } else {
                if (queue.empty()) {
                    if(temp.size() > 0) {
                        results.push_back(temp);
                    }
                    return results;
                }
                queue.push_back(NULL);
                results.push_back(temp);
                temp.clear();
            }
        }
        return results;
    }
};