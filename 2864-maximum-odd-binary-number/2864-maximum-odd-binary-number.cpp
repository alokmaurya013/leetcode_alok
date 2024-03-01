class Solution {
public:
    string maximumOddBinaryNumber(string s) {
       int c=0,n=s.size(),j=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                c++;
            }
        }
        string t="";
        for(int i=0;i<c-1;i++){
            t+='1';
        }
        for(int j=c-1;j<n-1;j++){
            t+='0';
        }
        t+='1';
        return t;
    }
};