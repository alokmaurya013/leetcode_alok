class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<int,int>mp;
  int ans=0;
  for(auto i:chars){
    mp[i]++;
  }     
  for(auto x:words){
    unordered_map<int,int>um;
    for(auto y:x){
      um[y]++;
    }
    bool flag=false;
    for(auto y:x){
      if(mp.find(y)==mp.end()||mp[y]<um[y]){
        flag=true;
        break;
      }
    }
    if(!flag){
       ans+=x.length();
    }
  }
  return ans; 
    }
};