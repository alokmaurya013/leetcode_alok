class Solution {
public:
    int countG(string s){
        int l=s.size(),c=0;
        for(int i=0;i<l;i++){
            if(s[i]=='G'){
                c++;
            }
        }
        return c;
    }
     int countM(string s){
        int l=s.size(),c=0;
        for(int i=0;i<l;i++){
            if(s[i]=='M'){
                c++;
            }
        }
        return c;
    }
     int countP(string s){
        int l=s.size(),c=0;
        for(int i=0;i<l;i++){
            if(s[i]=='P'){
                c++;
            }
        }
        return c;
    }
    int garbageCollection(vector<string>& g, vector<int>& t) {
        int n=g.size();
        int paper=0,glass=0,metal=0;
        int p=0,gt=0,m=0;
         paper=countP(g[0]);
        glass=countG(g[0]);
        metal=countM(g[0]);
        for(int i=1;i<n;i++){
            p+=t[i-1];
            gt+=t[i-1];
            m+=t[i-1];
            if(countP(g[i])){
               paper+=countP(g[i])+p;
                p=0;
            }
            if(countG(g[i])){
               glass+=countG(g[i])+gt;
                gt=0;
            }
            if(countM(g[i])){
               metal+=countM(g[i])+m;
                m=0;
            }
        }
        return paper+metal+glass;
    }
};