class Solution {
public:
    int kthGrammar(int n, int k) {
       if(n==1){
           return 0;
       }
       int l=1,r=pow(2,n-1);
        int ans=0;
        while(l<r){
            int mid=(l+r)/2;
            if(mid>=k){
                r=mid;
            }else{
                ans=1-ans;
                l=mid+1;
            }
        }
        return ans;
    }
};