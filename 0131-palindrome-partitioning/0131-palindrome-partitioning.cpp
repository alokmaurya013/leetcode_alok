class Solution {
public:

void solve(int ind,string s,vector<string>&t,vector<vector<string>>&ans){
  if(ind==s.size()){
      ans.push_back(t);
      return;
  }
  for(int i=ind;i<s.size();i++){
    if(isPalindrome(s,ind,i)){
        t.push_back(s.substr(ind,i-ind+1));
        solve(i+1,s,t,ans);
        t.pop_back();
    }
  }
}
bool isPalindrome(string s,int st,int e){
   while (st<=e)
   {
    if(s[st++]!=s[e--]){
        return false;
    }
   }
   return true;
}
    vector<vector<string>> partition(string s) {
         vector<vector<string>>ans;
    vector<string>t;
   solve(0,s,t,ans);
   return ans; 
    }
};