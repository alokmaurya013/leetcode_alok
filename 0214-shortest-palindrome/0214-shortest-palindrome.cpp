class Solution {
public:
    string shortestPalindrome(string s) {
        string str=s;
        reverse(str.begin(),str.end());
        str=s+'$'+str;
        int n=str.size();
        int i=1,j=0;
        vector<int>lps(n);
        while(i<n){
            if(str[i]==str[j]){
                j++;
                lps[i]=j;
                i++;
            }else{
                if(j!=0){
                    j=lps[j-1];
                }else{
                    i++;
                }
            }
        }
        i=lps[n-1];
        str=s.substr(i,n);
        reverse(str.begin(),str.end());
        return str+s;
    }
};