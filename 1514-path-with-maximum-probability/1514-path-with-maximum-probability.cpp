class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});   
        }
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start});
        vector<double>dist(n,INT_MIN);
        dist[start]=1;
        while(!pq.empty()){
            auto tp=pq.top();
            pq.pop();
            double dis=tp.first;
            int u=tp.second;
            for(auto it:adj[u]){
                int v=it.first;
                double w=it.second;
                if(dist[v]<dis*w){
                    dist[v]=dis*w;
                    pq.push({dist[v],v});
                }
            }
        }
        if(dist[end]==INT_MIN){
            return 0.00000;
        }else{
            return dist[end];
        }
    }
};