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
    void inorder(TreeNode* root,vector<int>&v){
        if(!root){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    void iterative(TreeNode* temp,vector<int>&v){
        stack<TreeNode*>st;
        if(!temp){
            return ;
        }
        while(!st.empty()||temp){
            while(temp){
                st.push(temp);
                temp=temp->left;
            }
            temp=st.top();
            st.pop();
            v.push_back(temp->val);
            temp=temp->right;
        }
    }
    void moris(TreeNode* root,vector<int>&v){
        TreeNode* temp=root;
        while(temp!=NULL){
            if(temp->left==NULL){
                v.push_back(temp->val);
                temp=temp->right;
            }else{
                TreeNode* prev=temp->left;
                while(prev->right && prev->right!=temp){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=temp;
                    temp=temp->left;
                }else{
                    prev->right=NULL;
                    v.push_back(temp->val);
                    temp=temp->right;
                }
            } 
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
       // inorder(root,v);
        //iterative(root,v);
        moris(root,v);
        return v;
    }
};