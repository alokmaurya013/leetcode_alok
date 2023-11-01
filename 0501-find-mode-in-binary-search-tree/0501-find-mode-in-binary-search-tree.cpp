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
  void inorder(unordered_map<int,int>&mp,TreeNode* root){
   if(root==NULL){
    return;
   }
   inorder(mp,root->left);
   mp[root->val]++;
   inorder(mp,root->right);
}
    vector<int> findMode(TreeNode* root) {
       unordered_map<int,int>mp;
       inorder(mp,root);
       int mx=0;
        vector<int>v;
      for(auto i:mp){
           mx=max(mx,i.second);
       } 
       for(auto i:mp){
           if(mx==i.second){
               v.push_back(i.first);
           }
       }
        return v;
    }
};