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
    void solve(TreeNode* root,int &sum,int isLeft){
        if(!root||(root->left==NULL&&root->right==NULL&&isLeft==0)){
            return;
        }
        if(root->left==NULL&&root->right==NULL&&isLeft==1){
            sum+=root->val;
            return;
        }
           solve(root->left,sum,1);
           solve(root->right,sum,0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
      int sum=0;
      int isLeft=0;
      solve(root,sum,isLeft);
    return sum;
    }
};