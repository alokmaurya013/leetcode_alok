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
        int position(vector<int>&inorder,int k,int start,int end){
          int n=inorder.size();
         for(int i=start;i<=end;i++){
             if(inorder[i]==k){
                 return i;
             }
         }
        return 0;
    }
        TreeNode* solve(vector<int>&postorder,vector<int>&inorder,int start,int end,int &index){
        if(start>end||index<0){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[index--]);
        int pos=position(inorder,root->val,start,end);
        root->right=solve(postorder,inorder,pos+1,end,index);
         root->left=solve(postorder,inorder,start,pos-1,index);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int index=n-1;
        return solve(postorder,inorder,0,n-1,index);
    }
};