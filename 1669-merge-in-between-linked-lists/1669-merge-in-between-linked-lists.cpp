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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp=list1,*temp1,*p;
        temp1=temp;
        int c=1;
        while(c<a){
            temp=temp->next;
            c++;
        }
        p=temp;
        while(c<=b){
            p=p->next;
            c++;
        }
        temp->next=list2;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=p->next;
        return temp1;
    }
};