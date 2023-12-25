class Solution {
public:
    int numDecodings(string s) {
     if(s.empty()||s[0]=='0'){
    return 0;
  }
  int n=s.size();
  int nprev=1,prev=1,curr=1;
  for(int i=1;i<n;i++){
      curr=0;
    int one=s[i]-'0';
    int two=stoi(s.substr(i-1,2));
      cout<<nprev<<" "<<prev<<" "<<one<<" "<<two<<endl;
    if(one!=0){
      curr+=prev;
    }
    if(two>=10&&two<=26){
      curr+=nprev;
    }
    nprev=prev;
    prev=curr;
  }
  return curr;
        
    }
};