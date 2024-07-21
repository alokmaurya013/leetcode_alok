class Solution {
public:
    void solve(int i,int n,vector<int>&nums,vector<vector<int>>&v,vector<int>r){
        if(i==n){
            v.push_back(r);
            return;
        }
        r.push_back(nums[i]);
        solve(i+1,n,nums,v,r);
        r.pop_back();
        solve(i+1,n,nums,v,r);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>r;
        int n=nums.size();
        for(int i=0;i<(1<<n);i++){
            v.push_back({});
            for(int j=0;j<n;j++){
              if(i&(1<<j)){  
                  v.back().push_back(nums[j]);
              }
            }
        }
        return v;
    }
};