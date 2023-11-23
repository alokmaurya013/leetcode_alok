class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>v;
        vector<int>a;
        int n=nums.size();
        int m=l.size();
        for(int i=0;i<m;i++){
            int flag=1;
            for(int j=l[i];j<=r[i];j++){
                a.push_back(nums[j]);
            }
            sort(a.begin(),a.end());
            int k=a.size();
            int d=a[1]-a[0];
            for(int j=2;j<k;j++){
                if(a[j]-a[j-1]!=d){
                    flag=0;
                    break;
                }
            }
            v.push_back(flag);
            a.clear();
        }
        return v;
    }
};