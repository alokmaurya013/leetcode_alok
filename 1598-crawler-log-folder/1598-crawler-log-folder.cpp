class Solution {
public:
    int minOperations(vector<string>& logs) {
        int c=0;
        for(auto s:logs){
           if(s=="./"){
               continue;
           }else if(s=="../"){
               if(c>0){
                   c--;
               }
           }else{
               c++;
           } 
        }
        return c;
    }
};