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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * cur1 = l1;
        ListNode * cur2 = l2;
        if(l1==nullptr && l2==nullptr) {
            return nullptr;
        }
        if(l2==nullptr) {
            return l1;
        }
        if(l1==nullptr) {
            return l2;
        }
        ListNode * head;
        if(l1->val<=l2->val) {
            head=l1;
            cur1=l1->next;
        }
        else {
            head=l2;
            cur2=l2->next;
        }
        ListNode * cur3=head;
        while(cur1!=nullptr || cur2!=nullptr) {
            if(cur2==nullptr) {
                cur3->next=cur1;
                return head;
            }
            else if(cur1==nullptr) {
                cur3->next=cur2;
                return head;
            }
            if(cur1->val<=cur2->val) {
                cur3->next=cur1;
                cur1=cur1->next;
            }
            else {
                cur3->next=cur2;
                cur2=cur2->next;
            }
            cur3=cur3->next;
        }
        return head;
    }
};