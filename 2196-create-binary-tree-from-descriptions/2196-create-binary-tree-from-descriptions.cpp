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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        unordered_map<int,bool>isChild;
        for(auto v:descriptions){
            if(mp.count(v[0])==0){
                TreeNode* pr=new TreeNode(v[0]);
                mp[v[0]]=pr;
            }
            if(mp.count(v[1])==0){
                TreeNode* child=new TreeNode(v[1]);
                mp[v[1]]=child;
            }
            if(v[2]==1){
                mp[v[0]]->left=mp[v[1]];
            }else{
                mp[v[0]]->right=mp[v[1]];
            }
            isChild[v[1]]=true;
        }
        TreeNode* ans=NULL;
        for(auto v:descriptions){
            if(isChild[v[0]]!=true){
                ans=mp[v[0]];
            }
        }
        return ans;
    }
};