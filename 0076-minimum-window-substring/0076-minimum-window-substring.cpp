class Solution {
public:
    bool check(vector<int>&s,vector<int>&t){
  bool isP=true;
  for(int i=0;i<256;i++){
   if(t[i]>s[i]){
      isP=false;
      break;
   }
  }
  return isP;
}
    string minWindow(string s, string t) {
         if(t.size()>s.size()){
      return "";
   }
   vector<int>tf(256,0);
   vector<int>sf(256,0);
   for(int i=0;i<t.size();i++){
      tf[t[i]]++;
   }
   int st=0,e=0;
   string ans="";
   while(st<=e&&e<s.size()){
      sf[s[e]]++;
   while(st<=e&&sf[s[st]]>=tf[s[st]]){
     string temp=s.substr(st,e-st+1);
     if(check(sf,tf)&&(ans.size()>temp.size()||ans=="")){
         ans=temp;
     }
     if(sf[s[st]]==tf[s[st]]){
      break;
     }
     sf[s[st]]--;
     st++;
   }
   e++;
   }
   return ans;  
    }
};