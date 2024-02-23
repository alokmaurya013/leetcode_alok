class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<flights.size();i++){
       int a=flights[i][0];
       int b=flights[i][1];
       int c=flights[i][2];
       adj[a].push_back({b,c});
    }    
    vector<long long>dist(n,LONG_LONG_MAX);
    priority_queue<pair<int,pair<long long,int>>,vector<pair<int,pair<long long,int>>>,greater<pair<int,pair<long long,int>>>>pq;
    pq.push({0,{0,src}});
    dist[src]=0;
    long long int ans=LONG_MAX;
    while (pq.size()){
        int stop=pq.top().first;
        long long d=pq.top().second.first;
        int a=pq.top().second.second;
        pq.pop();
        if(stop<=k+1&&a==dst){
            ans=min(ans,d);
        }
        if(stop<=k){
            for(auto it:adj[a]){
                int v=it.first;
                int w=it.second;
                if(dist[v]>w+d){
                    dist[v]=w+d;
                    pq.push({stop+1,{dist[v],v}});
                }
            }
        }
    }
    return ans==LONG_MAX?-1:ans;
    }
};