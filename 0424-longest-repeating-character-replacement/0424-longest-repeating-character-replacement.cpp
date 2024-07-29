class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<int,int>mp;
        int mf=0,ans=0,i=0,j=0;
        for(int j=0;j<n;j++){
            mp[s[j]]++;
            mf=max(mf,mp[s[j]]);
            if((j-i+1)-mf>k){
              mp[s[i]]--; 
                i++;
            }else{
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};