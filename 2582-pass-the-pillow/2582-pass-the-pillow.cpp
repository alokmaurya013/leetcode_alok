class Solution {
public:
    int passThePillow(int n, int time) {
        int c=time%(2*n-2);
        if(c>=n){
            return n-(c-n+1);
        }else{
            return c+1;
        }
    }
};