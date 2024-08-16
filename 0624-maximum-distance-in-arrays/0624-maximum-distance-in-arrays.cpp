class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int m=arr.size(),ans=0;
         int mi=arr[0][0],mx=arr[0].back();
        for(int i=1;i<m;i++){
            int n=arr[i].size();
            int tmi=arr[i][0],tmx=arr[i].back();
            int tans=max(abs(mx-tmi),abs(tmx-mi));
            ans=max(ans,tans);
            mi=min(mi,tmi);
            mx=max(mx,tmx);
            
        }
        return ans;
    }
};