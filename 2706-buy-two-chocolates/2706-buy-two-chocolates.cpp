class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n=prices.size();
        int fm=INT_MAX,sm=INT_MAX;
        for(int i=0;i<n;i++){
            if(prices[i]<fm){
                sm=fm;
                fm=prices[i];
            }else if(prices[i]<sm){
                sm=prices[i];
            }
        }
        if(fm+sm<=money){
            return money-(fm+sm);
        }else{
            return money;
        }
    }
};