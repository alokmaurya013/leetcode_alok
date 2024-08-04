class DisjointSet{
  vector<long long>rank,parent,size;
    public:
        DisjointSet(long long n){
            rank.resize(n+1,0);
            parent.resize(n+1,0);
            size.resize(n+1,0);
            for(long long i=0;i<n;i++){
                parent[i]=i;
                size[i]=1;
            }
            
        }
      long long find(long long node){
          if(node==parent[node]){
              return node;
          }
          return parent[node]=find(parent[node]);
      }
     void unionBySize(long long u,long long v){
         long long pu=find(u);
         long long pv=find(v);
         if(pu==pv){
             return ;
         }
         if(size[pu]<size[pv]){
             parent[pu]=pv;
             size[pv]+=size[pu];   
         }else{
             parent[pv]=pu;
             size[pu]+=size[pv];
         }
     }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        long long n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,long long>mp;
        for(long long i=0;i<n;i++){
            for(long long j=1;j<accounts[i].size();j++){
                string tmp=accounts[i][j];
                if(mp.find(tmp)==mp.end()){
                    mp[tmp]=i;
                }else{
                    ds.unionBySize(i,mp[tmp]);
                }
            }
        }
        vector<string>mergeList[n];
        for(auto it:mp){
            string s=it.first;
            long long id=it.second;
            long long pr=ds.find(id);
            mergeList[pr].push_back(s);
             
        }
        vector<vector<string>>ans;
        for(long long i=0;i<n;i++){
            if(mergeList[i].empty()){
                continue;
            }
            sort(mergeList[i].begin(),mergeList[i].end());
            vector<string>tmp;
            tmp.push_back(accounts[i][0]);
            for(long long j=0;j<mergeList[i].size();j++){
                tmp.push_back(mergeList[i][j]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};