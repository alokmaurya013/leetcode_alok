class Solution {
public:
    int maxScore(string s) {
        int one=count(s.begin(),s.end(),'1');
        int ans=0,zero=0,n=s.size();
        for(int i=0;i<n-1;i++){
            if(s[i]=='1'){
                one--;
            }else{
                zero++;
            }
            ans=max(ans,one+zero);
        }
        return ans;
    }
};