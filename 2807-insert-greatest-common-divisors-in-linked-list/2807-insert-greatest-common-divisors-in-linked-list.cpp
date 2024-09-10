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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
       int a=0,b=0;
        ListNode* tmp=head,*prev=head;
        if(tmp){
            a=tmp->val;
        }
        tmp=tmp->next;
        while(tmp){
            b=tmp->val;
            int g=__gcd(a,b);
            prev->next=new ListNode(g);
            prev=prev->next;
            prev->next=tmp;
            prev=prev->next;
            a=b;
            tmp=tmp->next;
        }
        return head;
    }
};