class Solution {
public:
using Pair = pair<char, int>;

struct Compare {
    bool operator()(const Pair& a, const Pair& b) const {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};
    string clearStars(string s) {
        priority_queue<Pair, vector<Pair>, Compare> pq;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                pq.push({s[i],i});
            }else{
                pq.pop();
            }
        }
       vector<pair<int,char>>v;
       while(!pq.empty()){
        Pair a=pq.top();
        pq.pop();
        v.push_back({a.second,a.first});
       }
       sort(v.begin(),v.end());
       string t="";
       for(pair<int,char>i:v){
          t+=i.second;
       }
        return t;
    }
};