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
    int position(vector<int>&inorder,int k){
          int n=inorder.size();
         for(int i=0;i<n;i++){
             if(inorder[i]==k){
                 return i;
             }
         }
        return 0;
    }
    TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int start,int end,int &index){
        if(start>end||index>=preorder.size()){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[index++]);
        int pos=position(inorder,root->val);
        root->left=solve(preorder,inorder,start,pos-1,index);
        root->right=solve(preorder,inorder,pos+1,end,index);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int index=0;
        return solve(preorder,inorder,0,n-1,index);
    }
};