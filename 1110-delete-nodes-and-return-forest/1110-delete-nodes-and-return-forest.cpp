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
    vector<TreeNode*>res;
    bitset<1001>del=0;
    void dfs(TreeNode* root,TreeNode* parent,bool isLeft){
        if(!root){
            return ;
        }
        if(del[root->val]){
            if(parent){
                if(isLeft){
                    parent->left=NULL;
                }else{
                    parent->right=NULL;
                }
            }
            dfs(root->left,NULL,1);
            dfs(root->right,NULL,0);
            delete root;
        }else{
            if(!parent){
                res.push_back(root);
            }
            dfs(root->left,root,1);
            dfs(root->right,root,0);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto i:to_delete){
            del[i]=1;
        }
        dfs(root,NULL,1);
        return res;
    }
};