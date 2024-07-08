class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>a(n,0);
        int c=n,i=0,t=0;
        while(c>1){
            if(a[i]==0){
                t++;
            }
            if(t==k){
               a[i]=1;
                t=0;
                c--;
            }
            i=(i+1)%n;
        }
        for(int i=0;i<n;i++){
            if(a[i]==0){
                c=i+1;
                break;
            }
        }
        return c;
    }
};