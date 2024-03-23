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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL,*curr=head,*nextN=NULL;
        while(curr){
            nextN=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextN;
        }
        return prev;
    }
    void merge(ListNode* list1,ListNode* list2){
        while(list2){
            ListNode* nextptr=list1->next;
            list1->next=list2;
            list1=list2;
            list2=nextptr;
        }
    }
    void reorderList(ListNode* head) {
        ListNode *prev=head,*fast=head,*slow=head;
        if(!head->next){
            return;
        }
        while(fast&&fast->next){
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        prev->next=NULL;
        ListNode* list1=head;
        ListNode* list2=reverse(slow);
        merge(list1,list2);
    }
};