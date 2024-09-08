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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       vector<ListNode*>v(k,NULL);
      ListNode* temp=head;
      int c=0,t=0;
      while(temp!=NULL){
        c++;
        temp=temp->next;
      }
      temp=head;  
      int a=c/k,b=c%k;
      ListNode* prev=NULL;
      int i=0;
      while (temp&&i<k){
        v[i]=temp;
        int j=0;
        while (j<(a+(b>0))){
         prev=temp;
         temp=temp->next;
         j++;
        }
        prev->next=NULL;
        i++;
        b--;
      }
      return v; 
    }
};