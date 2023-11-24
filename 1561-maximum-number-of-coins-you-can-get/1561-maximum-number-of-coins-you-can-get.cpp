class Solution {
public:
    int maxCoins(vector<int>& piles) {
      int n=piles.size();
        int m=n/3;
      int c=0;
      sort(piles.begin(),piles.end());
      for(int i=n-2;i>=m;i-=2){
          c+=piles[i];
      }  
        return c;
    }
    
};