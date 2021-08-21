#include <iostream>
#include <stdlib.h> 

 struct ListNode {
      int val;
      struct ListNode *next;
 };
 


struct ListNode* deleteDuplicates(struct ListNode* head){
    int bk[200000]={0};
     if (!head || !head->next)
            return head;
    struct ListNode *p = head;
    struct ListNode *q,*newhead;
    newhead = (ListNode*)malloc(sizeof(ListNode));
    q = newhead;
    bk[p->val]++;
    while(p->next)
    {
            bk[p->next->val]++;
            p = p->next;
    }
    p = head;
    while(p)
    {
        if(bk[p->val]==1)
        {
            q -> next = (ListNode*)malloc(sizeof(ListNode));
            q ->val = p->val;
            q = q->next;
        }
        p = p->next;
    }
   return newhead;
}
int main(int argc, char** argv) {
	return 0;
}
