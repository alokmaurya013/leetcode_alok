class Solution {
public:
    void dfs(int u,vector<vector<int>>&adj,vector<bool>&vis){
    vis[u]=1;
    for(int v:adj[u]){
       if(!vis[v]){
        dfs(v,adj,vis);
       }
    }
}
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
         vector<vector<int>>adj(n); 
       for(auto e:edges){
        adj[e[1]].push_back(e[0]);
       }
       vector<vector<int>>ans(n);
       vector<int>res;
       vector<bool>vis;
      for(int i=0;i<n;i++){
         vis.assign(n,0);
        dfs(i,adj,vis);
        res.clear();
        for(int j=0;j<n;j++){
          if(vis[j]&&i!=j){
            res.push_back(j);
          }
        }
        ans[i]=res;
      }
       return ans;
    }
};