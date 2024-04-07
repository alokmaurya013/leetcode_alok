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
     void iterative(TreeNode* temp,vector<int>&v){
         if(!temp){
             return ;
         }
        stack<TreeNode*>st;
         st.push(temp);
        while(!st.empty()){
            temp=st.top();
            st.pop();
            v.push_back(temp->val);
            if(temp->right){
              st.push(temp->right);}
            if(temp->left){
                st.push(temp->left);
            }
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        iterative(root,v);
        return v;
    }
};