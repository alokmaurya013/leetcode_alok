class Solution {
public:
    long long subArraysMax(vector<int>&nums){
         int n=nums.size();
        long long res=0;
        stack<int>st;
        for(int i=0;i<=n;i++){
            while(st.size()and(i==n or nums[st.top()]<nums[i])){
                int j=st.top();
                st.pop();
                int k=st.empty()?-1:st.top();
                res+=(long long)nums[j]*(i-j)*(j-k);
            }
            st.push(i);
        }
        return res;
    }
    long long subArraysMin(vector<int>&nums){
         int n=nums.size();
        long long res=0;
        stack<int>st;
        for(int i=0;i<=n;i++){
            while(st.size()and(i==n or nums[st.top()]>nums[i])){
                int j=st.top();
                st.pop();
                int k=st.empty()?-1:st.top();
                res+=(long long)nums[j]*(i-j)*(j-k);
            }
            st.push(i);
        }
        return res;
    }
    long long subArrayRanges(vector<int>& nums) {
        return subArraysMax(nums)-subArraysMin(nums);
        
    }
};