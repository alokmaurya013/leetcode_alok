class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int a=0,b=0,mi=INT_MAX;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                a++;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                a--;
            }
            mi=min(mi,a+b);
            if(s[i]=='b'){
                b++;
            }
        }
        return mi;
    }
};