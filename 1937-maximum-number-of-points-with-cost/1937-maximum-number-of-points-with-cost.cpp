class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
       int n=points.size();
        int m=points[0].size();
        vector<long long>dp(m,0);
        for(int i=0;i<m;i++){
            dp[i]=points[0][i];
        }
        for(int i=1;i<n;i++){
            vector<long long>left(m,0),right(m,0);
            left[0]=dp[0];
            for(int j=1;j<m;j++){
                left[j]=max(left[j-1]-1,dp[j]);
            }
            right[m-1]=dp[m-1];
            for(int j=m-2;j>=0;j--){
                right[j]=max(right[j+1]-1,dp[j]);
            }
            for(int j=0;j<m;j++){
                dp[j]=points[i][j]+max(left[j],right[j]);
            }
        }
        long long mx=INT_MIN;
        for(int i=0;i<m;i++){
            mx=max(mx,dp[i]);
        }
        return mx;
    }
};