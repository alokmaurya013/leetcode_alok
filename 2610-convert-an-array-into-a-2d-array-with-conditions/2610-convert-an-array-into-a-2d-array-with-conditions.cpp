class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>v;
        int c[201]={0};
        int  n=nums.size(),mx=0;
        for(int  i=0;i<n;i++){
            c[nums[i]]++;
            mx=max(mx,c[nums[i]]);
        }
        for(int i=0;i<mx;i++){
            vector<int>a;
            for(int j=1;j<=200;j++){
               if(c[j]!=0){
                   a.push_back(j);
                   c[j]--;
               }
            }
            v.push_back(a);
        }
        return v;
    }
};