class Solution {
public:
bool areAlmostEqual(int x, int y) {
    string s1 = to_string(x);
    string s2 = to_string(y);
   int a=-1,b=-1,diff=0;
    int n=s1.size();
    int m=s2.size();
    while(n<m){
        s1="0"+s1;
        n++;
    }
    while(m<n){
        s2="0"+s2;
        m++;
    }
    for (int i = 0; i < n; ++i) {
        if (s1[i] != s2[i]) {
            diff++;
            if(diff==1){
            a=i;
        }else if(diff==2){
            b=i;
        }else{
           return false; 
        }
        }
        
    }
    if (diff== 2) {
        swap(s1[a],s1[b]);
    }
    return s1==s2;
}
    int countPairs(vector<int>& nums) {
      int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i]==nums[j]||areAlmostEqual(nums[i],nums[j])) {
                count++;
            }
        }
    }
    return count;
    }
};