class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
 vector<int>v;
     int n=nums.size();
     map<int,vector<int>>mp;
     for(int i=n-1;i>=0;i--){
       int m=nums[i].size();
       for(int j=0;j<m;j++){
        mp[i+j].push_back(nums[i][j]);
       }
     }
     for(auto e:mp){
      for(auto ele:e.second){
        v.push_back(ele);
      }
     }
   return v;
    }
};