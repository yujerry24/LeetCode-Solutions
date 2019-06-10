#include <vector>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int x=0;
        vector<int> values;
        int counter=0;
        ListNode*cur=head;
        while(cur) {
            values.push_back(cur->val);
            cur=cur->next;
            
        }
        for(int i=0; i<values.size(); i++) {
            if(values.at(i)!=values.at(values.size()-i-1)) {
                return false;
            }
            if(i>values.size()-i-1) {
                break;
            }
        }
        return true;
    }
};