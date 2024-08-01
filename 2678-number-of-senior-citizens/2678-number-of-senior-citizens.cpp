class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n=details.size(),c=0;
        for(int i=0;i<n;i++){
            int age=0;
            for(int j=11;j<=12;j++){
                age=age*10+(details[i][j]-'0');
            }
            if(age>60){
                c++;
            }
        }
        return c;
    }
};