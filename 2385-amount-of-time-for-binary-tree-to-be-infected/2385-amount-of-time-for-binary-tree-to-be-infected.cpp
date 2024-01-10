#include<bits/stdc++.h>
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
    vector<int>adj[100001];
void buildAdj(TreeNode* root){
   if(!root){
    return;
   }
   int x=root->val;
   if(root->left){
    int l=root->left->val;
    adj[x].push_back(l);
    adj[l].push_back(x);
       buildAdj(root->left);
   }
   if(root->right){
    int r=root->right->val;
    adj[x].push_back(r);
    adj[r].push_back(x);
       buildAdj(root->right);
   }
}
    int amountOfTime(TreeNode* root, int start) {
       buildAdj(root);
       bool vis[100001]={0};
       queue<pair<int,int>>q;
       q.push({start,0});
       vis[start]=1;
       int c=0;
    
    while(!q.empty()){
        auto [u,d]=q.front();
        c=max(c,d);
        q.pop();
        for(int v:adj[u]){
            if(!vis[v]){
            q.push({v,d+1});
            vis[v]=1;
            }
        }
    }
    return c; 
    }
};