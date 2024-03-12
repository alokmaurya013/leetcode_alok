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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy=ListNode(0,head);
  ListNode* temp=&dummy;
  unordered_map<int,ListNode*>mp;
  int prefix=0;
  while(temp!=nullptr){
    prefix+=(temp->val);
    mp[prefix]=temp;
    temp=temp->next;
  }
  prefix=0;
  temp=&dummy;
  while(temp!=nullptr){
    prefix+=temp->val;
    temp->next=mp[prefix]->next;
     temp=temp->next;
  }
  return dummy.next;
    }
};