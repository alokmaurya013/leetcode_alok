class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int l=0,r=n-1;
        int flag=0;
        while(l<r){
            if(s[l]!=s[r]){
                flag=1;
                break;
            }
            while(l+1<r&&s[l]==s[l+1]){
                l++;
            }
            while(l<r-1&&s[r]==s[r-1]){
                r--;
            }
            l++;
            r--;
        }
        return r-l+1;
    }
};