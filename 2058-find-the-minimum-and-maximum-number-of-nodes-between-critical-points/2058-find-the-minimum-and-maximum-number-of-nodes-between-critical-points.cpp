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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>v;
        int i=1;
        ListNode* temp=head->next,*prev=head;
        while(temp->next!=NULL){
            int p=prev->val;
            int c=temp->val;
            int n=temp->next->val;
            if((p>c&&c<n)||(p<c&&c>n)){
                v.push_back(i);
            }
            prev=prev->next;
            temp=temp->next;
            i++;
        }
        if(v.size()<2){
            return {-1,-1};
        }else{
            int mi=INT_MAX;
            int mx=INT_MIN;
            int m=v.size();
            for(int i=1;i<m;i++){
                    mi=min(mi,v[i]-v[i-1]);
            }
            mx=v[m-1]-v[0];
            return {mi,mx};
        }
    }
};