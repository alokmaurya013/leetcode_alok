class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size(),m=nums1.size();
        vector<int>v(10001,-1),a(m);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty()){
              v[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
       for(int i=0;i<m;i++){
           a[i]=v[nums1[i]];
       }
        return a;
    }
};