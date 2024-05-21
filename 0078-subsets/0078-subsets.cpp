class Solution {
public:
    void solve(int i,int n,vector<int>&nums,vector<vector<int>>&v,vector<int>r){
        if(i==n){
           // sort(r.begin(),r.end());
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
        solve(0,n,nums,v,r);
       // sort(v.begin(),v.end());
        return v;
    }
};