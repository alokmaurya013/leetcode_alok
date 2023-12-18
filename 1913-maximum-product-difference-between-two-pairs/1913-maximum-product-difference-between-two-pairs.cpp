class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int firstMX=0,secondMX=0,firstMi=INT_MAX,secondMi=INT_MAX;
        for(int num:nums){
            if(num<firstMi){
                secondMi=firstMi;
                firstMi=num;
            }else if(num<secondMi){
                secondMi=num;
            }
            if(num>firstMX){
                secondMX=firstMX;
                firstMX=num;
            }else if(num>secondMX){
                secondMX=num;
            }
        }
        return (firstMX*secondMX)-(firstMi*secondMi);
    }
};