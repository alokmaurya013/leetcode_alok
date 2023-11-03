class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
       set<int>st;
  int t=target.size();
  for(int i=0;i<t;i++){
    st.insert(target[i]);
  }  
  vector<string>v;      
  for(int i=1;i<=n;i++){
     v.push_back("Push");
     if(st.find(i)==st.end()){
      v.push_back("Pop");
     }
     if(i==target[t-1]){
      break;
     }
  }
  return v;  
    }
};