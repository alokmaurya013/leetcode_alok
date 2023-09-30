class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        stack<int>s;
        int mx=INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<mx){
                return true;
            }
            while(!s.empty()&&nums[i]>s.top()){
                mx=s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};