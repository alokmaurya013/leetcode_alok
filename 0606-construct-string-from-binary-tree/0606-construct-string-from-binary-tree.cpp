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
        s+=to_string(root->val);
        if(root->left){
            s.push_back('(');
              prefix(root->left);
            s.push_back(')');
         }
        if(root->right){
            if(!root->left){
                s+="()";
            }
            s.push_back('(');
           prefix(root->right);
            s.push_back(')');
        }
    
    }
    string tree2str(TreeNode* root) {
        prefix(root);
        return s;
    }
};