class Solution {
public:
    int minBitFlips(int start, int goal) {
        int c=0;
        while(goal>0){
            if(((goal&1)!=(start&1))||((goal&0)!=(start&0))){
                c++;
            }
            goal=goal>>1;
            start=start>>1;
        }
        while(start>0){
            if(start&1){
              c++;
            }
             start=start>>1;
        }
        return c;
    }
};