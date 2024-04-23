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
    int kmpSearch(string text,string pattern){
        int m=pattern.length();
        int n=text.length(),ind=0;
        vector<int>lps(m,0);
        solvelps(pattern,lps);
        int i=0,j=0;
        while((n-i)>=(m-j)){
            if(pattern[j]==text[i]){
                j++;
                i++;
            }
            if(j==m){
               return i-j;
            }else if(i!=n&&pattern[j]!=text[i]){
                if(j!=0){
                    j=lps[j-1];
                }else{
                    i=i+1;
                }
            }
        }
        return -1;
    }
    int strStr(string text, string pattern) {
     return kmpSearch(text,pattern);
    }  
};