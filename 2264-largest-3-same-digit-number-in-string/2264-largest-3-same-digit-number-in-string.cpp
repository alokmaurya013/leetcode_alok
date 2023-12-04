class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
    int ans=-1;
        string s;
    for(int i=1;i<n-1;i++){
     int k=-1;
        string t="";
      if(num[i-1]==num[i]&&num[i]==num[i+1]){
         k=(num[i]-'0')*3;
          t+=num[i-1];
          t+=num[i];
          t+=num[i+1];
      }
      if(k>ans){
          ans=k;
          s=t;
      }
    }     
    return s;
    }
};