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
    
    TreeNode* solve(TreeNode* root,TreeNode* prev){
        if(!root){
            return prev;
        }
        TreeNode* r=solve(root->right,prev);
        TreeNode* l=solve(root->left,r);
        root->right=l;
        root->left=NULL;
        return root;
    }
    void flatten(TreeNode* root) {
         solve(root,NULL);
    }
};