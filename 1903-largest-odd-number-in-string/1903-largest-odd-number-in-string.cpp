class Solution {
public:
    bool isOdd(char ch){
        int a=ch-'0';
        if(a%2==1){
            return true;
        }
        return false;
    }
    string largestOddNumber(string num) {
        int n=num.size(),i=-1;
         for(int j=n-1;j>=0;j--){
             if(isOdd(num[j])){
                 i=j;
                 break;
             }
         }
      string s="";
        for(int j=0;j<=i;j++){
            s+=num[j];
        }
        return s;
    }
};