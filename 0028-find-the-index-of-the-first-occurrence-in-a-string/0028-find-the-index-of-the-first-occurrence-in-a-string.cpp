#define d 31
class Solution {
public:
    int q=INT_MAX;
    int RabinKarp(string text,string pattern){
        int m=pattern.size();
        int n=text.size();
        int p=0,t=0,h=1;
        for(int i=0;i<m-1;i++){
            long long a=d;
            a=a*h;
            h=(a)%q;
        }
        for(int i=0;i<m;i++){
            long long a=d,b=d;
            a=a*p+pattern[i];
            b=b*t+text[i];
            p=(a)%q;
            t=(b)%q;
        }
        for(int i=0;i<=n-m;i++){
            if(t==p){
                int j=0;
                for(j=0;j<m;j++){
                    if(text[i+j]!=pattern[j]){
                        break;
                    }
                }
                if(j==m){
                    return i;
                }
            }
             if(i<n-m){
                long long tt=text[i];
                 tt=tt*h;
                 tt=t-tt;
                 if(tt<0){
                     tt+=q;
                 }
                 tt=tt*d;
                 tt+=text[i+m];
                 t=(tt)%q;
               // t = (d * (t - txt[i] * h) + txt[i + M]) % q;
 
            if (t < 0){
                t = (t + q);
            }
             }   
        }
        return -1;
    }
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
    int  Zfunction(string text,string pattern){
         string temp=pattern+'$'+text;
         int n=temp.length();
         vector<int>z(n);
        getZarr(temp,z);
        for(int i=0;i<n;i++){
            if(z[i]==pattern.size()){
                return i-pattern.size()-1;
            }
        }
        return -1;
    }
    void getZarr(string temp,vector<int>&z){
        int n=temp.length();
        int L=0,R=0,k;
        for(int i=1;i<n;i++){
            if(i>R){
                L=R=i;
                while(R<n&&temp[R-L]==temp[R]){
                    R++;
                }
                z[i]=R-L;
                R--;
            }else{
                k=i-L;
                if(z[k]<R-i+1){
                    z[i]=z[k];
                }else{
                    L=i;
                    while(R<n&&temp[R-L]==temp[R]){
                        R++;
                    }
                    z[i]=R-L;
                    R--;
                }
            }
        }
    }
    int strStr(string text, string pattern) {
    // return kmpSearch(text,pattern);
    //    return RabinKarp(text,pattern);
        return Zfunction(text,pattern); 
    }  
};