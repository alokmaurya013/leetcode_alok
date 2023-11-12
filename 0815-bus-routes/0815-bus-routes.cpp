class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
          if(source==target){
        return 0;
       }  
       int maxStop=-1;
       for(auto r:routes){
        for(int s:r){
          maxStop=max(maxStop,s);
        }
       }
       if(maxStop<target){
        return -1;
       }
       int n=routes.size();
       vector<int>minBus(maxStop+1,INT_MAX);
       minBus[source]=0;
       bool flag=true;
       while (flag){
        flag=false;
        for(auto r:routes){
          int mi=n+1;
          for(auto s:r){
            mi=min(mi,minBus[s]);
          }
          mi++;
          for(auto s:r){
            if(minBus[s]>mi){
              minBus[s]=mi;
              flag=true;
            }
          }
        }
       }
       return (minBus[target]<n+1)?minBus[target]:-1;
    }
};