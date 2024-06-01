class Solution {
public:
    int scoreOfString(string s) {
       int c=0,n=s.size();
        for(int i=1;i<n;i++){
            c+=abs(s[i]-s[i-1]);
        }
        return c;
    }
};