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
#include<bits/stdc++.h>
class Solution {
public:
    bool solve(TreeNode* root,TreeNode* &prev){
       if(root==nullptr){
           return true;
       }
        if(!solve(root->left,prev)){
            return false;
        }
        if(prev!=nullptr&&root->val<=prev->val){
            return false;
        }
        prev=root;
        return solve(root->right,prev);
    }
    bool isValidBST(TreeNode* root) {
       TreeNode* prev=nullptr; 
      return solve(root,prev);
    }
};