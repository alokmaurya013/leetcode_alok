class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int zero=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero++;
            }
        }
        if(zero==0){
            return;
        }else{
            int i=0,j=0;
            while(i<n-zero&&j<n){
                while(i<n-zero&&nums[i]!=0){
                    i++;
                }
                j=max(i,j);
                while(j<n&&nums[j]==0){
                    j++;
                }
                cout<<i<<" "<<j<<endl;
                if(i<n-zero&&j<n&&i<j&&nums[i]==0&&nums[j]!=0){
                 swap(nums[i],nums[j]);
                }
                i++;
                j++;
            }
        }
        
    }
};