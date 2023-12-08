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
    string s="";
    void prefix(TreeNode* root){
        if(!root){
            return;
        }
        s+='(';
        s+=to_string(root->val);
        prefix(root->left);
        if(root->right){
            if(!root->left){
                s+="()";
            }
            prefix(root->right);
        }
        s+=')';
    }
    string tree2str(TreeNode* root) {
        prefix(root);
        int n=s.size();
        string t=s.substr(1,n-2);
        return t;
    }
};