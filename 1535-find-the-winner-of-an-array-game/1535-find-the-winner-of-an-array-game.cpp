class Solution {
public:
    int getWinner(vector<int>& a, int k) {
        int n=a.size();
      if(k==1){
    return max(a[0],a[1]);
   } 
   if(k>=n){
    return *max_element(a.begin(),a.end());
   }
   int c=0;
   int currele=a[0];
   for(int i=1;i<n;i++){
    if(currele>a[i]){
           c++;
    }else{
      currele=a[i];
      c=1;
    }
    if(c==k){
      return currele;
    }
   }
   return currele;  
    }
};