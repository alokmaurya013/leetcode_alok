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
    pair<int,int>postorder(TreeNode* root,int &c){
  if(root==NULL){
    return {0,0};
  }
  auto [sl,cl]=postorder(root->left,c);
  auto [sr,cr]=postorder(root->right,c);
  int sum=root->val,n=1;
     sum+=(sl+sr);
     n+=(cl+cr);
  if(sum/n==root->val){
    c++;
  }
  return {sum,n};
}
    int averageOfSubtree(TreeNode* root) {
        int c=0;
    postorder(root,c);
    return c;     
    }
};