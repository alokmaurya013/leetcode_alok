class Solution {
public:
    int dp[301][11];
int solve(vector<int>&jD,int n,int ind,int d){
   if(d==1){
      int mx=jD[ind];
      for(int i=ind;i<n;i++){
        mx=max(mx,jD[i]);
      }
      return mx;
   }
   if(dp[ind][d]!=-1){
    return dp[ind][d];
   }
   int mx=jD[ind];
   int res=INT_MAX;
  for(int i=ind;i<=n-d;i++){
      mx=max(mx,jD[i]);
      int curr=mx+solve(jD,n,i+1,d-1);
      res=min(res,curr);
  }
  return dp[ind][d]=res;
}
    int minDifficulty(vector<int>& jD, int d) {
       int  n=jD.size();
        if(n<d){
            return -1;
        }
        memset(dp,-1,sizeof(dp));
        return solve(jD,n,0,d);
    }
};