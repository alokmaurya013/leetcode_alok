class Solution {
public:
    int myAtoi(string s) {
   double r=0;
   int sign=1;
   int n=s.length();
   int i=0;
   while(s[i]==' '){
      i++;
   }
   if(s[i]=='+'){
      i++;
   }else if(s[i]=='-'){
         sign=-1;
         i++;
   }
   while(i<n&&s[i]>='0'&&s[i]<='9'){
      r=r*10+(s[i]-'0');
      i++;
   }
   r=sign*r;
   if(r>INT_MAX){
      r=INT_MAX;
   }
   if(r<INT_MIN){
      r=INT_MIN;
   }
   return int(r);
}
};