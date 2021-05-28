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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> linkedList;
        linkedList.clear();
        
        ListNode * cur = head;
        while(cur!=nullptr) {
            linkedList.push_back(cur);
            cur = cur->next;
        }
        
        // for(int i=0; i<linkedList.size(); i++) {
        //     cout<<linkedList.at(i)->val<<endl;
        // }
        
        if(n==linkedList.size()) {
            ListNode * remove = head;
            head = head->next;
            delete(remove);
            return head;
        }
        
        ListNode * remove = linkedList.at(linkedList.size()-n);
        ListNode * track = linkedList.at(linkedList.size()-n-1);
        track->next = track->next->next;
        delete(remove);
        return head;
    }
};