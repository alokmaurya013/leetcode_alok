class Solution {
public:
    int minOperations(string s) {
        int a=0,b=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(i&1){
                a+=(s[i]=='0');
            }else{
                a+=(s[i]=='1');
            }
        }
        for(int i=0;i<n;i++){
            if(i&1){
                b+=(s[i]=='1');
            }else{
                b+=(s[i]=='0');
            }
        }
        return min(a,b);
    }
};