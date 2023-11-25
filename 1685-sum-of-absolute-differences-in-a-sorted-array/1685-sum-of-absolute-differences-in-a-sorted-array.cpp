class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
       vector<int>res;
        int n=nums.size(),tot=0,mi=0,mx=0;
        tot=accumulate(nums.begin(),nums.end(),0);
        mx=tot;
        for(int i=0;i<n;i++){
           int c=abs(mi-nums[i]*i)+(mx-nums[i]*(n-i)); 
           res.push_back(c);
            mi+=nums[i];
            mx=tot-mi;
        }
        return res;
    }
    
};