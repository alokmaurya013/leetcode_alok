class Solution {
public:
    int minCost(string cl, vector<int>& nT) {
        int c=0,mx=nT[0],tot=nT[0];
        int n=cl.size();
        for(int i=1;i<n;i++){
            if(cl[i]==cl[i-1]){
                tot+=nT[i];
                if(mx<nT[i]){
                    mx=nT[i];
                }
            }else{
               c+=(tot-mx);
                mx=nT[i];
                tot=nT[i]; 
            }
        }
        c+=(tot-mx);
        return c;
    }
};