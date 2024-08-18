class Solution {
public:

     void sliding(string &s, int k, vector<pair<long long, int>> &dp) {
        long long count = 0;
        int l, r, ones, zeros;
        l = r = ones = zeros = 0;
        while (r<s.length()) {
            if (s[r] == '1') {
                ones++;
            }
            else {
                zeros++;
            }
            while (ones > k && zeros > k) {
                if (s[l++] == '1') {
                    ones--;
                }
                else {
                    zeros--;
                }
            }
            dp[r].first = count += r-l+1;
            dp[r].second = l;
            r++;
        }        
    }
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
         vector<long long> res;
        vector<pair<long long, int>> dp(s.length());
        sliding(s, k, dp);
        for (auto q : queries) {
            if (q[0] == 0) {
                res.push_back(dp[q[1]].first);
            }
            else {
                long long cur = dp[q[1]].first - dp[q[0]-1].first;

                for (int i=q[0]; i<=q[1]; i++) {
                    if (dp[i].second >= q[0]) {
                        break;
                    }
                    cur -= (q[0]-dp[i].second);
                }
                res.push_back(cur);
            }
        }
        return res;
    }
};