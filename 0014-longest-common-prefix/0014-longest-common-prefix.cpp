class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==1){
            return strs[0];
        }
        for(int i=0;i<n;i++){
            if(strs[i].size()==0){
                return "";
            }
        }
        int k=0,j=0,flag=1;
        string res="";
        while(k<strs[0].size()){
            for(int i=0;i<n-1;i++){
                if(strs[0][j]==strs[i+1][j]){
                    continue;
                }else{
                    flag=0;
                    break;
                }
            }
            if(flag){
                res+=strs[0][j];
                j++;
            }
            k++;
        }
        return res;
    }
};