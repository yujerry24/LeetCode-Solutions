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
    ListNode* swapPairs(ListNode* head) {
        
        if(head==nullptr) {
            return nullptr;
        }
        if(!head->next) {
            return head;
        }
        ListNode * temp= head->next;
        head->next=head->next->next;
        temp->next=head;
        ListNode * cur = temp->next;
        while(cur->next!=nullptr) {
            if(cur->next->next==nullptr) {
                break;
            }
            else {
                ListNode * trav = cur->next;
                cur->next=cur->next->next;
                trav->next=cur->next->next;
                cur->next->next=trav;
                cur=cur->next->next;
            }
            
        }
        return temp;
    }
};