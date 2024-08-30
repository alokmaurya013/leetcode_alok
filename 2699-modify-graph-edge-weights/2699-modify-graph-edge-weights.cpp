#define pii pair<int,int>

class Solution {
public:
    int m,n;
    vector<int>tmpEdge;
    vector<vector<pii>>adj;
    void buildGraph(vector<vector<int>>&edges){
        for(int i=0;i<m;i++){
            int u=edges[i][0];
             int v=edges[i][1];
             int w=edges[i][2];
            
            if(w>0){
                adj[u].push_back({v,w});
                adj[v].push_back({u,w});
            }else{
                tmpEdge.push_back(i);
            }
        }
    }
    int dijkstra(int src,int dest,vector<vector<pii>>&adj){
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();
            if(u==dest){
                return d;
            }
            for(auto[v,w]:adj[u]){
                int nd=d+w;
                if(dist[v]>nd){
                    dist[v]=nd;
                    pq.push({nd,v});
                }
            }
        }
        return INT_MAX;
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dest, int target) {
        this->n=n;
        m=edges.size();
        adj.resize(n);
        buildGraph(edges);
        int dist=dijkstra(src,dest,adj);
        if(dist<target){
            return {};
        }
    for(auto i:tmpEdge){
        edges[i][2]=target+1;
    }
        if(dist==target){
            return edges;
        }
        for(auto i:tmpEdge){
         auto &e=edges[i];
            int u=e[0];
            int v=e[1];
            e[2]=1;
            adj[u].push_back({v,1});
            adj[v].push_back({u,1});
            int d=dijkstra(src,dest,adj);
            if(d<=target){
                e[2]+=target-d;
                return edges;
            }
        }
        return {};
    }
};