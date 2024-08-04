class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        vector<int>dx={-1,0,1,0,-1};
        while(!pq.empty()){
            pair<int,pair<int,int>>t=pq.top();
            pq.pop();
            int dist=t.first;
            int i=t.second.first;
            int j=t.second.second;
            if(i==n-1&&j==n-1){
                return dist;
            }
            for(int k=0;k<4;k++){
                int dr=i+dx[k];
                int dc=j+dx[k+1];
                if(dr>=0&&dr<n&&dc>=0&&dc<n&&vis[dr][dc]==0){
                    vis[dr][dc]=1;
                    pq.push({max(dist,grid[dr][dc]),{dr,dc}});
                }
            }
        }
        return -1;
    }
};