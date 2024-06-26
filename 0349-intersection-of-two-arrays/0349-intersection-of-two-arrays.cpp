class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      int n=nums1.size(),m=nums2.size(),i=0,j=0;
      unordered_set<int>st;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        while(i<n&&j<m){
           if(nums1[i]<nums2[j]){
               i++;
           }else if(nums1[i]>nums2[j]){
               j++;
           } else{
               st.insert(nums1[i]);
               i++;
               j++;
           }
        }
        vector<int>v;
        for(auto i:st){
            v.push_back(i);
        }
        return v;
    }
};