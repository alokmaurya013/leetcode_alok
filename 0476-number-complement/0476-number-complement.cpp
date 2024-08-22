class Solution {
public:
    int findComplement(int num) {
        int bit=floor(log2(num))+1;
        return ((1LL<<bit)-1)^num;
    }
};