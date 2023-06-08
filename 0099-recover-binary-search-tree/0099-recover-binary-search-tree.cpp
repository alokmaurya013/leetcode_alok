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
    void storevec(TreeNode* root, vector<int>&v){
   if(root==nullptr){
    return;
   }
   storevec(root->left,v);
   v.push_back(root->val);
   storevec(root->right,v);
}
void correctBSTUtil(TreeNode* root,vector<int>&v,int &ind){
  if(root==NULL){
    return;
  }
  correctBSTUtil(root->left,v,ind);
  root->val=v[ind];
  ind++;
  correctBSTUtil(root->right,v,ind);
}
    void recoverTree(TreeNode* root) {
        vector<int>v;
  storevec(root,v);
  sort(v.begin(),v.end());
  int ind=0;
  correctBSTUtil(root,v,ind);
    }
};