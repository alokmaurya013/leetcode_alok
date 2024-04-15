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
    int sum=0;
    void solve(TreeNode* root,int v){
        if(!root){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            v=v*10+root->val;
            sum+=v;
            v=v/10;
        }
        if(root->left){
            v=v*10+root->val;
            solve(root->left,v);
            v/=10;
        }
        if(root->right){
            v=v*10+root->val;
            solve(root->right,v);
            v/=10;
        }
    }
    int sumNumbers(TreeNode* root) {
        int v=0;
       solve(root,v); 
        return sum;
    }
};