class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        int arr[26]={0};
        if(n!=m){
            return false;
        }
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        for(int i:arr){
            if(i!=0){
                return false;
            }
        }
        return true;
    }
};