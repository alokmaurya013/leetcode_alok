class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         unordered_map<int,int>mp;
        int n=nums.size();
      for(int i=0;i<n;i++){
        mp[nums[i]]++;
      }
     vector<int>a;
     for(auto i:mp){
        if(i.second>(n/3)){
          a.push_back(i.first);
        }
     }
     return a; 
    }
};