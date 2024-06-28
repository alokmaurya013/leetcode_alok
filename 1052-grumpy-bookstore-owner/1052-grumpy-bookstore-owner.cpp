class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int mx=0,gmx=0,curr=0;
        int n=customers.size();
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                mx+=customers[i];
            }
        }
        for(int i=0;i<minutes;i++){
            if(grumpy[i]){
                gmx+=customers[i];
            }
        }
        curr=gmx;
        for(int i=minutes;i<n;i++){
            if(grumpy[i-minutes]){
                curr-=customers[i-minutes];
            }
            if(grumpy[i]){
               curr+=customers[i]; 
            }
            gmx=max(gmx,curr);
        }
        return mx+gmx;
    }
};