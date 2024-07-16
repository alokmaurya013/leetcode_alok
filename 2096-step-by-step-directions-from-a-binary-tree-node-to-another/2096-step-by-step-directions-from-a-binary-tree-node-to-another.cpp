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
    TreeNode* lca(TreeNode* root,int s,int d){
        if(root==NULL||root->val==s||root->val==d){
            return root;
        }
        TreeNode* l=lca(root->left,s,d);
        TreeNode* r=lca(root->right,s,d);
        if(l==NULL){
            return r;
        }else if(r==NULL){
            return l;
        }else{
            return root;
        }
    }
    bool solve(TreeNode* root,int target,string &s){
        if(root==NULL){
            return false;
        }
        if(root->val==target){
            return true;
        }
        s.push_back('L');
        if(solve(root->left,target,s)){
            return true;
        }
        s.pop_back();
        s.push_back('R');
        if(solve(root->right,target,s)){
            return true;
        }
        s.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lc=lca(root,startValue,destValue);
        string ls,ld;
        solve(lc,startValue,ls);
        solve(lc,destValue,ld);
        for(int i=0;i<ls.size();i++){
            ld.insert(0,"U");
        }
        return ld;
    }
};