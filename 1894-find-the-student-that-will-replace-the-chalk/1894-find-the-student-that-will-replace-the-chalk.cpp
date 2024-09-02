class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long s=0,n=chalk.size();
        
        for(int i=0;i<n;i++){
            s+=chalk[i];
        }
        k=k%s;
        int i=0;
        while(i<n){
            if(chalk[i]<=k){
                k-=chalk[i];
            }else{
                break;
            }
            i++;
        }
        return i;
    }
};