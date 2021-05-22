/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL && l2==NULL) {
        return NULL;
    }
    if(l2==NULL) {
        return l1;
    }
    if(l1==NULL) {
        return l2;
    }
    struct ListNode * head = malloc(sizeof(struct ListNode));
    int value = l1->val + l2->val;
    head->val=value%10;
    int remainder = value /10;
    head->next=NULL;
    struct ListNode * cur1=l1->next;
    struct ListNode * cur2=l2->next;
    struct ListNode * cur3 = head;
    while(cur1!=NULL || cur2 !=NULL || remainder !=0) {
        struct ListNode * temp = malloc (sizeof(struct ListNode));
        int val1=0;
        int val2=0;
        if(cur1) {
            val1=cur1->val;
        }
        if(cur2) {
            val2=cur2->val;
        }
        int sum = val1 + val2 + remainder;
        temp->val=(sum)%10;
        remainder = sum/10;
        temp->next=NULL;
        cur3->next=temp;
        cur3=cur3->next;
        
        if(cur1) {
            cur1=cur1->next;
        }
        if(cur2) {
            cur2=cur2->next;
        }
    }
    return head;
}

