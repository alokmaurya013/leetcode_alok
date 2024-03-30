class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        int i,j,k;
        sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        for(int i=0;i<n-2;i++){
            if(i!=0&&nums[i]==nums[i-1]){
                continue;
            }
            j=i+1;
            k=n-1;
            while(j<k){
                long long a=nums[i];
                a+=nums[j];
                a+=nums[k];
                if(a==0){
                    v.push_back({nums[i],nums[j],nums[k]});
                    int c=nums[j];
                    int d=nums[k];
                    j++;
                    k--;
                    while(c==nums[j]&&j<k){
                       j++; 
                    }
                    while(d==nums[k]&&j<k){
                        k--;
                    }
                }else if(a>0){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return v;
    }
};