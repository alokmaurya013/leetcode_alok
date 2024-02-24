#define pi pair<int,int>
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
      vector<pair<int,int>>adj[n];
   for(auto i:meetings){
     adj[i[0]].push_back({i[1],i[2]});
     adj[i[1]].push_back({i[0],i[2]});
   }
   priority_queue<pi,vector<pi>,greater<pi>>pq;
   pq.push({0,0});
   pq.push({0,firstPerson});
   vector<int>vis(n,0);
   while(!pq.empty()){
    auto i=pq.top();
    int time=i.first;
    int person=i.second;
    pq.pop();
    if(vis[person]){
      continue;
    }
    vis[person]=true;
    for(auto i:adj[person]){
      if(!vis[i.first]&&i.second>=time){
        pq.push({i.second,i.first});
      }
    }
   }
   vector<int>res;
   for(int i=0;i<n;i++){
    if(vis[i]){
      res.push_back(i);
    }
   }
   return res;  
    }
};