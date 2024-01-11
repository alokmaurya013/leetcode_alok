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
    int solve(TreeNode* root,int mi,int mx){
        if(!root){
            return mx-mi;
        }
        mx=max(mx,root->val);
        mi=min(mi,root->val);
        return max(solve(root->left,mi,mx),solve(root->right,mi,mx));
    }
    int maxAncestorDiff(TreeNode* root) {
        int mi=root->val,mx=root->val;
        return solve(root,mi,mx);
    }
};