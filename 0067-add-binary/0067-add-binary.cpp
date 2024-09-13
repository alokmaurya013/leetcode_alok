class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size();
        int m=b.size();
        int c=0,i=n-1,j=m-1;
        string t="";
        while(i>=0||j>=0|c>0){
            int first=0,second=0;
            if(i>=0){
                first=(a[i]-'0');
                i--;
            }
            if(j>=0){
                second=(b[j]-'0');
                j--;
            }
            int tmp=first+second+c;
            if(tmp==3){
                t+='1';
                c=1;
            }else if(tmp==2){
                t+='0';
                c=1;
            }else{
                t+=to_string(tmp);
                c=0;
            }
        }
       reverse(t.begin(),t.end());
        return t;
    }
};