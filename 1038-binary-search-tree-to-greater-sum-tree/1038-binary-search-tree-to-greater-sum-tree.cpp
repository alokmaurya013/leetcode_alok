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
    void inorder(vector<int>&a,TreeNode * root){
        if(!root){
            return;
        }
        inorder(a,root->left);
        a.push_back(root->val);
        inorder(a,root->right);
    }
     void inorder2(unordered_map<int,int>&mp,TreeNode * root){
        if(!root){
            return;
        }
        inorder2(mp,root->left);
        root->val=mp[root->val];
        inorder2(mp,root->right);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>a;
        inorder(a,root);
        int n=a.size();
        vector<int>b(n,0);
        b[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--){
            b[i]=a[i]+b[i+1];
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp.insert({a[i],b[i]});
        }
        inorder2(mp,root);
        return root;
    }
};