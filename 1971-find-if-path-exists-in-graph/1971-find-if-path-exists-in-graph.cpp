class Solution {
public:
    void dfs(vector<int>adj[],int i,int destination,vector<int>&vis){
        vis[i]=1;
        for(auto j:adj[i]){
            if(vis[j]==0){
                dfs(adj,j,destination,vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>vis(n,0);
        vector<int>adj[n];
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(adj,source,destination,vis);
        if(vis[destination]==0){
            return false;
        }
        return true;
    }
};