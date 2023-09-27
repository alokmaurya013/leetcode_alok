class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long length=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                length*=(s[i]-'0');
            }else{
                length++;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(isdigit(s[i])){
                length/=(s[i]-'0');
                k%=length;
            }else{
                if(k==0||k==length){
                    return string("")+s[i];
                }
                length--;
            }
        }
        return "" ;
    }
};