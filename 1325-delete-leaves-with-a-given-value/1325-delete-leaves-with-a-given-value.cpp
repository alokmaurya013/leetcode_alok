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
    TreeNode* solve(TreeNode* root, int target,TreeNode* parent=NULL){
        if(!root){
            return NULL;
        }
        root->left=solve(root->left,target,root);
        root->right=solve(root->right,target,root);
        if(root->val==target&&root->left==NULL&&root->right==NULL){
            if(parent){
                delete root;
            }
            return NULL;
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
       return solve(root,target);
    }
};