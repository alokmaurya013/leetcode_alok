class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mx=0,ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            mx=max(mx,mp[nums[i]]);
        }
        for(auto i:mp){
            if(i.second==mx){
                ans+=i.second;   
            }
        }
        return ans;
    }
};