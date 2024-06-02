// class Solution {
// public:
// using Pair = pair<char, int>;

// struct Compare {
//     bool operator()(const Pair& a, const Pair& b) const {
//         if (a.first == b.first) {
//             return a.second < b.second;
//         }
//         return a.first > b.first;
//     }
// };
//     string clearStars(string s) {
//         priority_queue<Pair, vector<Pair>, Compare> pq;
//         int n=s.size();
//         for(int i=0;i<n;i++){
//             if(s[i]!='*'){
//                 pq.push({s[i],i});
//             }else{
//                 pq.pop();
//             }
//         }
//        vector<Pair>v;
//        while(!pq.empty()){
//         auto a=pq.top();
//         pq.pop();
//         v.push_back({a.second,a.first});
//        }
//        sort(v.begin(),v.end());
//        string t="";
//        for(auto i:v){
//         t+=i.second;
//        }
//         return t;
//     }
// };
class Solution {
public:
    
    struct node{
        char ch;
        int idx;
    };
    
    struct compare{
        bool operator()(const node &a, const node &b){
            if(a.ch == b.ch) return a.idx < b.idx; // max heap
            return a.ch > b.ch; // min heap
        }
    };
    
    string clearStars(string s) {
        int n = s.length();
        
        priority_queue<node,vector<node>,compare> pq;
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch=='*'){
                if(pq.size() > 0) pq.pop();
            }else{
                pq.push({ch, i});
            }
        }
        
        vector<pair<int,char>> v;
        while(pq.size() > 0){
            node cur = pq.top();
            pq.pop();
            
            v.push_back({cur.idx, cur.ch});
        }
		
        sort(v.begin(), v.end()); // since we need to maintain orginal indexing of chars in string
        
        string ans = "";
        for(pair<int,char> p : v) ans += p.second;
        
        return ans;
    }
};