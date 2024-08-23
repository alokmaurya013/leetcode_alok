class Solution {
public:
    string fractionAddition(string s) {
        int n=s.size();
        int num1=0,num2=0,d1=0,d2=1;
        int flag=false,sign=1;
        for(int i=0;i<n;i++){
            if(i==0&&s[i]=='-'){
                sign=-1;
                continue;
            }
            if(s[i]>='0'&&s[i]<='9'){
                if(!flag){
                    num1=num1*10+(s[i]-'0');
                }else{
                    d1=d1*10+(s[i]-'0');
                }
            }else if(s[i]=='/'){
                flag=true;
            }else{
                num1*=sign;
                num2=num2*d1+num1*d2;
                d2=d1*d2;
                int g=abs(__gcd(num2,d2));
                num2/=g;
                d2/=g;
                num1=0;
                d1=0;
                flag=false;
                sign=(s[i]=='-'?-1:1);
            }
        }
        if(flag){
            num1*=sign;
            num2=num1*d2+num2*d1;
            d2=d1*d2;
            int g=abs(__gcd(num2,d2));
            num2/=g;
            d2/=g;
        }
        return to_string(num2)+'/'+to_string(d2);
    }
};