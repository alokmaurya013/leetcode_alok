class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     int n=nums.size();
    int mx=0;
    unordered_set<int>st;
    for(auto i:nums){
        st.insert(i);
    }
    for(auto i:st){
        if(st.find(i-1)==st.end()){
            int curr=i;
            int count=1;
            while(st.find(curr+1)!=st.end()){
                curr++;
                count++;
            }
            mx=max(mx,count);
        }
    }
    return mx;
    }
};