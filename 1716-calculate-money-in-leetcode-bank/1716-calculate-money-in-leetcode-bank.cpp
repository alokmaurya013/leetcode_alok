class Solution {
public:
    int totalMoney(int n) {

       int m=n/7;
        int c=n%7;
        int k=c*(c+1);
       // cout<<28*m<<" "<<(m*(m-1))/2<<" "<<k/2<<" "<<m*c<<endl;
       return (28*m+((m*(m-1))/2)*7+k/2+m*c);
    }
};