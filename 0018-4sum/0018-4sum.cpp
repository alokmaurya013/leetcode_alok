class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>v;
        int n=nums.size();
        int i=0,j,k,l;
        sort(nums.begin(),nums.end());
        while(i<n-3){
            j=i+1;
            while(j<n-2){
            k=j+1,l=n-1;
            while(k<l){
                long long a=nums[i];
                a+=nums[j];
                a+=nums[k];
                a+=nums[l];
                if(a==target){
                    v.push_back({nums[i],nums[j],nums[k],nums[l]});
                    int b=nums[k];
                    int c=nums[l];
                      k++,l--;
                    while(b==nums[k]&&k<l){
                        k++;
                    }
                    while(c==nums[l]&&k<l){
                        l--;
                    }
                }else if(a>target){
                    l--;
                }else{
                    k++;
                }
            }
               int d=nums[j]; 
                j++;
                while(d==nums[j]&&j<n-2){
                 j++;
                }
            }
             int d=nums[i]; 
                i++;
                while(d==nums[i]&&i<n-3){
                 i++;
                }
        }
        return v;
    }
};