class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        vector<int>v;
        sort(deck.begin(),deck.end());
        queue<int>q;
        q.push(deck[n-1]);
        for(int i=n-2;i>=0;i--){
            q.push(q.front());
            q.pop();
            q.push(deck[i]);
        }
        while(!q.empty()){
            v.push_back(q.front());
            q.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};