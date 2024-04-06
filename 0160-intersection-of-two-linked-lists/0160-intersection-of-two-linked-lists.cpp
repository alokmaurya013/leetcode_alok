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
    int length(ListNode* temp){
        int c=0;
        while(temp){
            temp=temp->next;
            c++;
        }
        return c;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         if(!headA||!headB){
             return NULL;
         }
        int a=length(headA),b=length(headB);
        if(a>b){
            while(a>b){
                headA=headA->next;
                a--;
            }
        }else if(a<b){
            while(a<b){
                headB=headB->next;
                b--;
            }
        }
        while(headA&&headB){
            if(headA==headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};