#include<bits/stdc++.h>
class Solution {
public:
    bool judgeSquareSum(int c) {
       for (long a = 0; a * a <= c; a++) { 
           long t=c-a*a;
            double b = sqrt(t);     
            if (b == (int)b) {                
                return true;                 
            }
        }
        return false;   
    }
};