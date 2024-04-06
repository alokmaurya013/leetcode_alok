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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0,i=0;
        ListNode* temp=head,*p;
        while(temp){
            temp=temp->next;
            n++;
        }
        temp=head;
       if(n!=0){ k=k%n;}
        if(!head||!head->next||k==0||k==n){
            return head;
        }
        while(i<n-k-1){
          temp=temp->next;
            i++;
        }
        p=temp->next;
        temp->next=NULL;
        temp=p;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        head=p;
        return head;
    }
};