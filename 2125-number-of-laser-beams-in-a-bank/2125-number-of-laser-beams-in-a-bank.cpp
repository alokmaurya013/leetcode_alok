class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int c=0; 
    int n=bank.size();
    int prev=0,curr=0;
    for(int i=0;i<n;i++){
        curr=count(bank[i].begin(),bank[i].end(),'1');
        if(curr!=0){
            c+=curr*prev;
            prev=curr;
        }
    }    
    return c;
    }
};