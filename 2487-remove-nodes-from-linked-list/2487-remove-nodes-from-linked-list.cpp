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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        ListNode* temp=head;
        while(temp!=nullptr){
            while(!st.empty()&&st.top()->val<temp->val){
                st.pop();
            }
            st.push(temp);
            temp=temp->next;
        }
        ListNode* nxt=nullptr;
        while(!st.empty()){
            ListNode* p=st.top();
            st.pop();
            p->next=nxt;
            nxt=p;
        }
        return nxt;
    }
};