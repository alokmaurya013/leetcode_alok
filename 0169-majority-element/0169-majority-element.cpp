class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size(),x;
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
            if(mp[i]>n/2){
                x=i;
                break;
            }
        }
       return x; 
    }
};