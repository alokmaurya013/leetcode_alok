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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
                vector<vector<int>>v;
        if(!root){
            return v;
        }
    queue<TreeNode*>q;
        q.push(root);
        int c=0;
        while(!q.empty()){
            int n=q.size();
            vector<int>r;
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                r.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            if(c==0){
                c=1;
            }else{
                reverse(r.begin(),r.end());
                c=0;
            }
            v.push_back(r);
        }
        return v;
    }
};