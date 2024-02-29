/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool evenodd(vector<int>&v,int i){
        int n=v.size();
        if(i%2==0){
            if(v[0]%2==0){
                return false;
            }
            for(int i=1;i<n;i++){
                if(v[i]%2==0||v[i]<=v[i-1]){
                    return false;
                }
            }
        }else{
             if(v[0]%2==1){
                return false;
            }
            for(int i=1;i<n;i++){
                if(v[i]%2==1||v[i]>=v[i-1]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        int i=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
               vector<int>v;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            if(!evenodd(v,i)){
                return false;
            }
            i++;
        }
        return true;
    }
};