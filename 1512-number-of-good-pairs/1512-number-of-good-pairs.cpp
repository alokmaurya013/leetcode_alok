class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int c=0;
        for(auto i:mp){
            int t=i.second;
            c+=(t*(t-1))/2;
        }
        return c;
    }
};