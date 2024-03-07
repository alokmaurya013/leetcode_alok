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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int c=0;
        while(temp!=nullptr){
           c++;
            temp=temp->next;
        }
            int k=c/2;
            c=0;
            temp=head;
            while(c<k){
            temp=temp->next;
                c++;
          }
            return temp;
        
    }
};