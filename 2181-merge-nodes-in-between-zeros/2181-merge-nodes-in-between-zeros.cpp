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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head->next,*res=new ListNode(0);
        int sum=0;
        head=res;
        while(temp!=NULL){
            if(temp->val==0){
                res->next=new ListNode(sum);
                res=res->next;
                sum=0;
            }else{
                sum=sum+temp->val;
            }
            temp=temp->next;
        }
        return head->next;
    }
};