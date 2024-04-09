class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int  n=tickets.size();
        int t=0;
        while(tickets[k]!=0){
            if(tickets[k]>1){
                for(int i=0;i<n;i++){
                    if(tickets[i]>0){
                        t++;
                        tickets[i]--;
                    }
                }
            }else{
               for(int i=0;i<=k;i++){
                   if(tickets[i]>0){
                       t++;
                       tickets[i]--;
                   }
               }
            }
        }
        return t;
    }
};