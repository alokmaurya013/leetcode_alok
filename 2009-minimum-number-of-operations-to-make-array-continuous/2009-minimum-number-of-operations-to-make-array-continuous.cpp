class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
  int ans=n;
  unordered_set<int>s;
  for(int i:nums){
    s.insert(i);
  }
  vector<int>v(s.begin(),s.end());
  sort(v.begin(),v.end());
  int j=0,m=v.size();
  for(int i=0;i<m;i++){
    while (j<m&&v[j]<v[i]+n){
       j++;
    }
    ans=min(ans,n-j+i);
  }
  return ans;
    }
};