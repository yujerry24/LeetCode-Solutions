class Solution {
public:

struct mycmp{

 bool operator()(ListNode * a,ListNode * b)
 {
     return a->val > b->val;
 }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {

 priority_queue<ListNode*,vector<ListNode *>,mycmp>pq;
 
 for(int i=0;i<lists.size();i++)
 {
     if(lists[i])
     {
         ListNode * ptr = lists[i];
         while(ptr != NULL)
         {
             pq.push(ptr);
             ptr = ptr->next;
         }
     }
     
 }
 
 ListNode * ptr = new ListNode(-1);
 ptr->next = NULL;
 ListNode * dummy = ptr;
 
 while(!pq.empty())
 {
     ListNode *temp = pq.top();
     ptr->next = temp;
     pq.pop();
     
     ptr = ptr->next;
 }
 ptr->next = NULL;
 
 return dummy->next;
}
};