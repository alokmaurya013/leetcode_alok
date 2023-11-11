class Graph {
public:
    vector<vector<pair<int,int>>>adj;
    int m;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        m=n;
   for(auto e:edges){
    adj[e[0]].push_back({e[2],e[1]});
   }
    }
    void addEdge(vector<int>e) {
        adj[e[0]].push_back({e[2],e[1]});
    }
    int shortestPath(int node1, int node2) {
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(m,INT_MAX);
    dist[node1]=0;
    pq.push({0,node1});
    while (!pq.empty())
    {
      auto [d,i]=pq.top();
      pq.pop();
      if(i==node2){
        addEdge({node1,node2,d});
        return d;
      }
      if(d>dist[i]){continue;}
      int d2;
      for(auto [w,j]:adj[i]){
        d2=d+w;
        if(d2<dist[j]){
          dist[j]=d2;
          pq.push({d2,j});
        }
      }
    }
    return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */