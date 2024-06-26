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
    void inorder(TreeNode* root,vector<TreeNode*>&a){
      if(root==NULL){
          return;
      }
    inorder(root->left,a);
    a.push_back(root);
    inorder(root->right,a);
    }
    TreeNode* newBST(vector<TreeNode*>&a,int s,int e){
        if(s>e){
            return NULL;
        }
        int mid=(s+e)/2;
        TreeNode* temp=a[mid];
        temp->left=newBST(a,s,mid-1);
        temp->right=newBST(a,mid+1,e);
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>a;
        inorder(root,a);
        return newBST(a,0,a.size()-1);
    }
};