class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c=__builtin_popcount(n);
        return c;
    }
};