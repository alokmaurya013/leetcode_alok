class Solution {
public:
   
    int minimumDifference(vector<int>& nums) {
        int n=(nums.size())/2;
       vector<vector<int>>left(n+1),right(n+1);
       int tot=accumulate(nums.begin(),nums.end(),0);
        int sum=tot/2;
        for(int i=0;i<(1<<n);i++){
         int c=0,a=0,b=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    c++;
                    a+=nums[j];
                    b+=nums[j+n];
                }
            }
            left[c].push_back(a);
            right[c].push_back(b);
        }
        for(int i=0;i<=n;i++){
            sort(right[i].begin(),right[i].end());
        }
        //int tot=left[n][0]+right[n][0];
        int ans=INT_MAX;
        for(int i=0;i<=n;i++){
            for(int l:left[i]){
                int sr=sum-l;
                auto it=lower_bound(right[n-i].begin(),right[n-i].end(),sr);
                
                if(it!=right[n-i].end()){

                    ans=min(ans,abs(tot-2*(l+(*it))));
                }
            }
        }
        
        return ans;
    }
};