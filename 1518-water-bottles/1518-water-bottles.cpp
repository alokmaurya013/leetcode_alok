class Solution {
public:
    int numWaterBottles(int bt,int ex) {
        int sum=bt;
        while(bt>=ex){
            sum+=(bt/ex);
            bt=(bt/ex)+(bt%ex);
        }
        return sum;
    }
};