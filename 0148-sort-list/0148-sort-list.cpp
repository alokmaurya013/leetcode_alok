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
    ListNode* findMiddle(ListNode* r){
        if(r==NULL||r->next==NULL){
            return r;
        }
       ListNode* slow=r;
       ListNode* fast=r->next;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* mergeLL(ListNode* p,ListNode* q){
        ListNode* dummy=new ListNode(-1);
        ListNode* tmp=dummy;
        while(p!=NULL&&q!=NULL){
            if(p->val<=q->val){
                tmp->next=p;
                p=p->next;
            }else{
                tmp->next=q;
                q=q->next;
            }
            tmp=tmp->next;
        }
        if(p!=NULL){
            tmp->next=p;
        }else{
            tmp->next=q;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* mid=findMiddle(head);
        ListNode* r=mid->next;
        mid->next=NULL;
        ListNode* l=head;
        l=sortList(l);
        r=sortList(r);
        return mergeLL(l,r);
    }
};