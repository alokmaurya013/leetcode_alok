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
        stack<TreeNode*>s,t;
         s.push(temp);
        while(!s.empty()){
            temp=s.top();
            s.pop();
            t.push(temp);
             if(temp->left){
                s.push(temp->left);
            }
            if(temp->right){
              s.push(temp->right);
            }
        }
        while(!t.empty()){
            v.push_back(t.top()->val);
            t.pop();
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        iterative(root,v);
        return v;
    }
};