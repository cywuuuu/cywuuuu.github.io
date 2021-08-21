#include <iostream>

/**
 * Definition for singly-linked list.*/
 	struct ListNode {
    int val;
	struct ListNode *next;
 	};
 

typedef struct ListNode *LinkList;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL ) return l2;
    if(l2 == NULL ) return l1; 
     LinkList listc,p=l1,q=l2,r;//r为前半段的尾巴 p、 q为比较点 
	 //p、q中的最小点 是我们将要纳入的新点 
        if(l1->val<=l2->val){
           	listc=l1;
            r=l1;
            p=l1->next;
        }
        else{
            listc=l2;
            r=l2;
            q=l2->next;
        }
        while(p!=NULL && q!=NULL){
        	if(p->val<=q->val){
            	r->next = p;//纳入我们 
            	r=p;//更新排序末尾 
                p = p->next;//换新的p 
            }
            else{
          	    r->next = q;
                r=q;
                q = q->next;
            }
         }
         r->next= p!=NULL ?p:q;//p!=NULL 时 p未满 末尾r连去p上； 
         return listc;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	return 0;
}
