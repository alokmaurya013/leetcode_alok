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
    int widthOfBinaryTree(TreeNode* root) {
       vector<int>v;
       if(!root){
           return 0;
       } 
       int ans=1;
       queue<pair<TreeNode*,long long int>>q;
       q.push({root,0});
       while(!q.empty()){
           int size=q.size();
           int d1=0,d2=0;
           int mn=q.front().second;
           for(int i=0;i<size;i++){
               auto tp=q.front();
               TreeNode* node=tp.first;
               long long int k=tp.second-mn;
               q.pop();
               if(i==0){
                   d1=k;
               }
               if(i==size-1){
                   d2=k;
               }
               if(node->left){
                   q.push({node->left,2*k+1});
               }
               if(node->right){
                    q.push({node->right,2*k+2});
               }
           }
           ans=max(ans,d2-d1+1);
       }
       return ans;
    }
};