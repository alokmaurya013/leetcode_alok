class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
       int ones=0,zeros=0;
        for(auto i:students){
         if(i==0){
             zeros++;
         }else{
             ones++;
         }   
        }
        for(auto i:sandwiches){
            if(i==0){
                if(zeros>0){
                    zeros--;
                }else{
                    break;
                }
            }else{
                if(ones>0){
                    ones--;
                }else{
                    break;
                }
            }
        }
        return ones+zeros;
    }
};