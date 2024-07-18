class Solution {
public:
    void dfs(int i,vector<int>&vis,vector<vector<int>>&isConnected,int n){
        vis[i]=1;
        for(int j=0;j<n;j++){
           if(vis[j]==0&&isConnected[i][j]){
               dfs(j,vis,isConnected,n);
           } 
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        int c=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,vis,isConnected,n);
                c++;
            }
        }
        return c;
    }
};