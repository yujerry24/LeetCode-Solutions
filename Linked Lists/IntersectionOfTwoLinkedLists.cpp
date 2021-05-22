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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> a;
        ListNode * cur1=headA;
        ListNode * cur2=headB;
        while(cur1) {
            a.push_back(cur1);
            cur1=cur1->next;
        }
        while(cur2) {
            if(find(a.begin(), a.end(),cur2)!=a.end()) {
                return cur2;
            }
            cur2=cur2->next;
        }
        return nullptr;
        
    }
};