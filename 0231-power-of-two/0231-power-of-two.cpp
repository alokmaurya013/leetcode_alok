class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        int c=__builtin_popcount(n);
        return (c==1);
    }
};