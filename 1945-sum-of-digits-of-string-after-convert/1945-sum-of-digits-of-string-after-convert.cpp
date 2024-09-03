class Solution {
public:
    int getLucky(string s, int k) {
        string t="";
        int n=s.size();
        for(int i=0;i<n;i++){
            t+=to_string(s[i]-'a'+1);
        }
        int sum=0;
        while(k--){
            sum=0;
            for(int i=0;i<t.size();i++){
                sum+=(t[i]-'0');
            }
            t=to_string(sum);
        }
        return sum;
    }
};