class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xr=start^goal;
        int c=0;
        while(xr){
            c+=xr&1;
            xr>>=1;
        }
        return c;
    }
};