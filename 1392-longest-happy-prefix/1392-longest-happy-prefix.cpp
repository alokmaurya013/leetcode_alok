class Solution {
public:
     void solvelps(string pattern,vector<int>&lps){
        int m=pattern.size();
        int len=0,i=1;
        lps[0]=0;
        while(i<m){
            if(pattern[i]==pattern[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len!=0){
                    len=lps[len-1];
                }else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    string longestPrefix(string s) {
        int n=s.size();
        vector<int>lps(n,0);
        solvelps(s,lps);
        int m=lps[n-1];
        string t=s.substr(0,m);
        return t;
    }
};