class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
              int n1=nums1.size(),n2=nums2.size();
  vector<int>a;
  int i=0,j=0;
  while (i<n1&&j<n2){
    if(nums1[i]<=nums2[j]){
        a.push_back(nums1[i]);
        i++;
    }else{
        a.push_back(nums2[j]);
        j++;
    }
  }
  while (i<n1)
  {
    a.push_back(nums1[i]);
    i++;
  }
   while (j<n2)
  {
    a.push_back(nums2[j]);
    j++;
  }
  int l=a.size();
  if(l%2==0){
    return double(a[l/2-1]+a[l/2])/2;
  }else{
    return a[l/2];
  }  
    }
};