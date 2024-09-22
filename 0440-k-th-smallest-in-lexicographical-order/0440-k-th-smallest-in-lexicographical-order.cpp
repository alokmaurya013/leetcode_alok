class Solution {
public:
    long long getSteps(long long n,long long curr,long long next){
        long long steps=0;
        while(curr<=n){
            steps+=min(n+1,next)-curr;
            curr*=10;
            next*=10;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        int curr=1;
        k--;
        while(k>0){
            long long step=getSteps(n,curr,curr+1);
            if(step<=k){
                curr++;
                k-=step;
            }else{
                curr*=10;
                k--;
            }
            
        }
        return curr;
    }
};