class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int mp[1000001]={0};
    for (int x: nums1) {
        for(int i=1;i<=sqrt(x);i++){
            if(x%i==0){
                mp[i]++;
                if(i!=x/i){
                    mp[x/i]++;
                }
            }
        }
    }
    long long pair= 0;
    for (int num : nums2){
            if (num*k<=1000000) {
                pair += mp[num*k];
            }
    }
    return pair;
    }
};