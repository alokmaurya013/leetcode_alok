class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0,sell=1,profit=0,n=prices.size(),mx=0;
        while(sell<n){
            int curr=prices[sell]-prices[buy];
            if(curr>0){
                mx=max(mx,curr);
            }
            if(curr<0){
                buy=sell;
            }
            sell++;
        }
        return mx;
    }
};