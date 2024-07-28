class Solution {
public:
    int secondTime(int step,int time,int change){
       int ans=0;
        for(int i=0;i<step;i++){
            int t=ans/change;
            if(t&1){
                ans=(t+1)*change;
            }
            ans+=time;
        }
        return ans;
    }
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>>adj(n+1);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>dist1(n+1,INT_MAX),dist2(n+1,INT_MAX);
        queue<pair<int,int>>q;
        q.push({1,0});
        dist1[1]=0;
        while(!q.empty()){
            auto t=q.front();
            int u=t.first;
            int d=t.second;
            q.pop();
            for(auto v:adj[u]){
                int newD=d+1;
                if(newD<dist1[v]){
                    dist2[v]=dist1[v];
                    dist1[v]=newD;
                    q.push({v,newD});
                }else if(newD>dist1[v]&&newD<dist2[v]){
                    dist2[v]=newD;
                    q.push({v,newD});
                }
            }
        }
        int step=dist2[n];
        if(step==INT_MAX){
            return -1;
        }
        return  secondTime(step,time,change);
    }
};