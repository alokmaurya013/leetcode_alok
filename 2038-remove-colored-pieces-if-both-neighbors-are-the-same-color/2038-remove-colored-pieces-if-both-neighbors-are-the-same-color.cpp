class Solution {
public:
    bool winnerOfGame(string s) {
        int n=s.size();
        int cA=0,cB=0;
        if(n<3){
            return false;
        }
        for(int i=1;i<n-1;i++){
            if(s[i]=='A'){
                if(s[i]==s[i-1]&&s[i+1]==s[i]){
                    cA++;
                }
            }
             else{
                if(s[i]==s[i-1]&&s[i+1]==s[i]){
                    cB++;
                }
            }
        }
        if(cA<=cB){
            return false;
        }else{
            return true;
        }
    }
};