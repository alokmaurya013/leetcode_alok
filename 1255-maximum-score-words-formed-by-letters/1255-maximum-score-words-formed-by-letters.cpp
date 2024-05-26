class Solution {
public:
    int solve(vector<string>&w,vector<int>&s,vector<int>&cnt,int i){
        if(i==w.size()){
            return 0;
        }
        int score=0;
        int notTake=solve(w,s,cnt,i+1);
        int valid=1;
        for(char c:w[i]){
            cnt[c-'a']--;
            if(cnt[c-'a']<0){
                valid=0;
            }
            score+=s[c-'a'];
        }
        int take=0;
        if(valid){take=score+solve(w,s,cnt,i+1);}
        for(char c:w[i]){
            cnt[c-'a']++;
        }
        return max(take,notTake);
    }
    int maxScoreWords(vector<string>& w, vector<char>& l, vector<int>& s) {
        vector<int>cnt(26,0);
        for(char i:l){
            cnt[i-'a']++;
        }
        return solve(w,s,cnt,0);
    }
};