class Solution {
public:
    int convert(vector<int>&mp,int num){
         int t=num;
            if(t<10){
                return mp[num];
            }
            int c=0;
            int base=1;
            while(t){
                c=c+mp[t%10]*base;
                t=t/10;
                base=base*10;
            }
       return c;
    }
    vector<int> sortJumbled(vector<int>& mp, vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&mp,this](const int &a,const int &b){
            int first=this->convert(mp,a);
            int second=this->convert(mp,b);
            return first<second;
        });
        return nums;
    }
};