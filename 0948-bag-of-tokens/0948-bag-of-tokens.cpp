class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
      int n=tokens.size();
        if(n==0){
            return 0;
        }
      int l=0,r=n-1;
        sort(tokens.begin(),tokens.end());
        if(power<tokens[0]){
            return 0;
        }
        int score=0,maxScore=0;
        while(l<=r){
            while(l<=r&&power>=tokens[l]){
                power-=tokens[l];
                l++;
                score++;
            }
            maxScore=max(maxScore,score);
            if(l<r&&score>0){
                power+=tokens[r--];
                score--;
            }else{
                break;
            }
        }
        return maxScore;
    }
};