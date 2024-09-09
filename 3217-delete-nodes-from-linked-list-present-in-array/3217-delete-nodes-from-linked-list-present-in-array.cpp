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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>st(nums.begin(),nums.end());
        ListNode* tmp=new ListNode(0,head);
        ListNode* newHead=tmp;
        while(tmp->next){
            if(st.count(tmp->next->val)){
                tmp->next=tmp->next->next;
            }else{
                tmp=tmp->next;
            }
        }
        return newHead->next;
    }
};