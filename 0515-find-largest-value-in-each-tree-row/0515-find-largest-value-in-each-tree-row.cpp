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
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>>levelorder;
  queue<pair<TreeNode*,int>>q;
  q.push({root,0});
  while(!q.empty()){
    TreeNode* temp=q.front().first;
    int n=q.front().second;
    q.pop();
    if(temp==NULL){
      continue;
    }
    if(levelorder.size()<=n){
      levelorder.resize(n+1);
    }
    levelorder[n].push_back(temp->val);
    if(temp->left!=NULL){
      q.push({temp->left,n+1});
    }
    if(temp->right!=NULL){
      q.push({temp->right,n+1});
    }
  }
  vector<int>res;
  int n=levelorder.size();
  for(int i=0;i<n;i++){
    int mx=*max_element(levelorder[i].begin(),levelorder[i].end());
    res.push_back(mx);
  }
  return res;
}
};