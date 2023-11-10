class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& a) {
        int n=a.size();
  map<int,vector<int>>mp;
  for(int i=0;i<n;i++){
    mp[a[i][0]].push_back(a[i][1]);
    mp[a[i][1]].push_back(a[i][0]);
  }
  int curr,prev=-100000000;
  vector<int>res;
  for(auto i:mp){
    if(i.second.size()==1){
      curr=i.first;
      break;
    }
  }
  res.push_back(curr);
  for(int i=1;i<=n;i++){
    vector<int>&val=mp[curr];
    int p=(val[0]==prev)?val[1]:val[0];
    res.push_back(p);
    prev=curr;
    curr=p;
  }
  return res;
    }
};