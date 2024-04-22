class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n=version1.size();
        int m=version2.size();
        int i=0,j=0,flag=0,num1=0,num2=0;
        while(i<n||j<m){
            num1=0,num2=0;
            while(i<n&&version1[i]!='.'){
                num1=num1*10+(version1[i]-'0');
                i++;
            }
            while(j<m&&version2[j]!='.'){
                num2=num2*10+(version2[j]-'0');
                j++;
            }
            if(num1>num2){
                flag=1;
                return 1;
            }
            if(num2>num1){
                return -1;
            }
            if(i<n){
                i++;
            }
            if(j<m){j++;}
        }
        return 0;
    }
};