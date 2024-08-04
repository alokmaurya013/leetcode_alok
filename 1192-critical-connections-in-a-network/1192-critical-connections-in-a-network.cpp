class Solution {
    int timer=1;
public:
    void  dfs(int u,int parent,vector<int>&vis,vector<int>adj[],int low[],int tin[],vector<vector<int>>&bridge){
        vis[u]=true;
        tin[u]=low[u]=timer;
        timer++;
        for(auto v:adj[u]){
            if(v==parent){continue;}
            if(vis[v]==0){
                dfs(v,u,vis,adj,low,tin,bridge);
                low[u]=min(low[v],low[u]);
                if(low[v]>tin[u]){
                    bridge.push_back({v,u});
                }
            }else{
                low[u]=min(low[v],low[u]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>>bridge;
        dfs(0,-1,vis,adj,low,tin,bridge);
        return bridge;
    }
};