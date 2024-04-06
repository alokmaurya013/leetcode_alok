/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode* p,ListNode* q=NULL){
        ListNode *prev=NULL,*curr=NULL;  
        while(p!=q){
            curr=p->next;
            p->next=prev;
            prev=p;
            p=curr;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1||!head||!head->next){
            return head;
        }
        
        ListNode* dummy=new ListNode(0,head),*back,*forward;
        back=dummy;
        forward=head;
        
        while(back){
            int i=0;
            while(i<k&&forward){
               forward=forward->next;
                i++;
            }
            if(i!=k){
                break;
            }
            ListNode* t=back->next;
            back->next=reverse(back->next,forward);
            t->next=forward;
            back=t;
        }
        return dummy->next;
    }
};