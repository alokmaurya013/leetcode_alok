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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>v(m,vector<int>(n,-1));
        int row1=0,col1=0,rown=m-1,coln=n-1;
        while(head){
        for(int i=col1;i<=coln;i++){
            v[row1][i]=head->val;
            head=head->next;
            if(head==NULL){break;}
        }
         if(head==NULL){break;}
        row1++;
        for(int i=row1;i<=rown;i++){
            v[i][coln]=head->val;
            head=head->next;
             if(head==NULL){break;}
        }
             if(head==NULL){break;}
            coln--;
        for(int i=coln;i>=col1;i--){
            v[rown][i]=head->val;
            head=head->next;
             if(head==NULL){break;}
        }
             if(head==NULL){break;}
            rown--;
            for(int i=rown;i>=row1;i--){
                v[i][col1]=head->val;
                head=head->next;
                 if(head==NULL){break;}
            }
            col1++;
        }
        return v;
    }
};