class Solution {
public:
  string convert(string s){
  string temp="#";
  for(char c:s){
    temp+=c;
    temp+="#";
  }
  return temp;
}
    string longestPalindrome(string s) {
       string t=convert(s);
   int n=t.size();
   int l=0;
   int r=-1;
   int center;
   int maxLen=0;
   vector<int>p(n);
   p[0]=0;
   for(int i=1;i<n;i++){
    int k;
    if(i>r){
      k=0;
    }else{
      int j=l+(r-i);
      if(j-p[j]>l){
        p[i]=p[j];
        continue;
      }else{
        k=r-i;
      }
    }
    while ((i-k>=0)&&(i+k<n)&&t[i-k]==t[i+k]){
      k++;
    }
    k--;
    p[i]=k;
    if(p[i]>maxLen){
      maxLen=p[i];
      center=i/2;
    }
    if(i+k>r){
      l=i-k;
      r=i+k;
    }
   }
   return s.substr(center-(maxLen/2),maxLen);  
    }
};