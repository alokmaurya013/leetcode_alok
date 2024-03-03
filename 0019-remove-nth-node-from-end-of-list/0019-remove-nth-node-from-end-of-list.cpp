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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m=0;
        ListNode* temp=head,*curr;
        while(temp!=nullptr){
            temp=temp->next;
            m++;
        }
        int k=m-n+1,c=1;
        if(k==1){
            return head->next;
        }
        temp=head;
        while(c<k-1){
            temp=temp->next;
            c++;
        }
        curr=temp->next;
        temp->next=curr->next;
        curr->next=nullptr;
        return head;
    }
};