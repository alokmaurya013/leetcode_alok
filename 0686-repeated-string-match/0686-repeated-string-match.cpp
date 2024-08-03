class Solution {
public:
    const int prime=101;
    long long createHash(string &str,int end){
        long long hash=0;
        for(int i=0;i<=end;i++){
            hash=(hash*256+str[i])%prime;
        }
        return hash;
    }
    long long reCalculateHash(string &str,int oldI,int newI,int oldHash,long long h){
 long long newHash = (oldHash - str[oldI] *h)%prime;
    newHash = (newHash * 256 + str[newI]) % prime;        
        if(newHash<0){
            newHash+=prime;
        }
        return newHash;
    }
    bool checkEqual(string &s1,string &s2,int start1,int start2,int len){
        for(int i=0;i<len;i++){
            if(s1[start1+i]!=s2[start2+i]){
                return false;
            }
        }
        return true;
    }
    int RabinKarp(string &a,string &b){
        long long m=a.size();
        long long n=b.size();
    
        long long hashText=createHash(a,n-1);
        long long hashPattern=createHash(b,n-1);
         long long h = 1; 
    for (int i = 0; i < n - 1; i++) {
        h = (h * 256) % prime;
    }
        for(int i=0;i<=m-n;i++){
            if(hashText==hashPattern&&checkEqual(a,b,i,0,n)){
                return 1;
            }
            if(i<m-n){
                hashText=reCalculateHash(a,i,i+n,hashText,h);
            }
        }
        return 0;
    }
    int repeatedStringMatch(string a, string b) {
        if(a==b){
            return 1;
        }
        int c=1;
        string temp=a;
        while(temp.size()<b.size()){
            temp+=a;
            c++;
        }
        if(temp==b){
            return c;
        }
        if(RabinKarp(temp,b)==1){
            return c;
        }
        temp+=a;
        if(RabinKarp(temp,b)==1){
            return c+1;
        }
        return -1;
    }
};