class Solution {
public:
    double solve(vector<int>& nums1, vector<int>& nums2,int n1,int n2){
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
    double binarySearch(vector<int>& nums1, vector<int>& nums2,int n1,int n2){
        if(n1>n2){
            return binarySearch(nums2,nums1,n2,n1);
        }
        int n=n1+n2;
        int left=(n1+n2+1)/2;
        int low=0,high=n1;
        while(low<=high){
        int mid1=(low+high)/2;
        int mid2=left-mid1;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(mid1<n1){r1=nums1[mid1];}
            if(mid2<n2){r2=nums2[mid2];}
            if(mid1-1>=0){l1=nums1[mid1-1];}
            if(mid2-1>=0){l2=nums2[mid2-1];}
            if(l1<=r2&&l2<=r1){
                if(n%2==1){return max(l1,l2);}
                return (max(l1,l2)+min(r1,r2))/2.0;
            }else if(l1>r2){
                high=mid1-1;
            }else{
                low=mid1+1;
            }
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
              int n1=nums1.size(),n2=nums2.size();
              return binarySearch(nums1,nums2,n1,n2);
    }
};