class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int c=0;
        for(auto it:mp){
            int k=it.second;
            if(k==1){
                return -1;
            }else if(k%3==0){
                c+=k/3;
            }else{
                c+=(k/3+1);
            }
        }
        return c;
    }
};