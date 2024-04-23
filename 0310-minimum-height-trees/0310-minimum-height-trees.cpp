#include<bits/stdc++.h>
#include<vector>
class Solution {
public:
void addEdge(int u,int v,vector<int>&degree,vector<vector<int>>&adj){
    adj[u].push_back(v);
    adj[v].push_back(u);
    degree[u]++;
    degree[v]++;
}
void rootMinH(vector<int>&res,int n,vector<int>&degree,vector<vector<int>>&adj){
  queue<int>q;
   for(int i=0;i<n;i++){
    if(degree[i]==1){
      q.push(i);
    }
   }
   if(n==1){
     res.push_back(0);
   }
   while (!q.empty()){
    int s=q.size();
    res.clear();
    for(int i=0;i<s;i++){
      int t=q.front();
      q.pop();
      res.push_back(t);
      for(auto j=adj[t].begin();j!=adj[t].end();j++){
        degree[*j]--;
        if(degree[*j]==1){
          q.push(*j);
        }
      }
    }
   }
   
   return ;
}
    vector<int> findMinHeightTrees(int n, vector<vector<int>>&edges) {
      vector<int>degree(n,0),res;
      vector<vector<int>>adj(n);
         for(auto &e:edges){
               addEdge(e[0],e[1],degree,adj);
         }
         rootMinH(res,n,degree,adj);
         return res;
    }
};