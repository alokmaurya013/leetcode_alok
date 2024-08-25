class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            string s=to_string(nums[i]);
            unordered_map<int,int>mp1;
            mp1[nums[i]]++;
            for(int j=0;j<s.size();j++){
                for(int k=j+1;k<s.size();k++){
                    swap(s[j],s[k]);
                    mp1[stoi(s)]++;
                    string t=s;
                    for(int l=0;l<t.size();l++){
                        for(int m=l+1;m<t.size();m++){
                            swap(s[l],s[m]);
                            mp1[stoi(s)]++;
                            swap(s[l],s[m]);
                        }
                    }
                    swap(s[j],s[k]);
                }
            }
            for(auto p:mp1){
                ans+=mp[p.first]-(p.first==nums[i]);
                
                if(to_string(p.first).size()!=s.size()){
                    ans+=mp[p.first]-(p.first==nums[i]);
                }
            }
        }
        return ans/2;
    }
};