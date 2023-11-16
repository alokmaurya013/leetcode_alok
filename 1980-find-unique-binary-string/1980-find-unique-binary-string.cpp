class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string s;
        int n=nums.size(),flag=0;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            int b=stoi(nums[i],0,2);
            a[i]=b;
        }
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            if(a[i]!=i){
                int x;
                if(i!=0){
                     x=(int)log2(i);
                }else{x=i;}
                s=bitset<64>(i).to_string().substr(64-n);
                flag=1;
                break;
            }
        }
        if(flag==0){
            s=bitset<64>(n).to_string().substr(64-n);
        }
        return s;
    }
};