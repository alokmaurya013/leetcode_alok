class StockSpanner {
public:
    stack<pair<int,int>>s;
    int i;
    StockSpanner() {
         i=0;
    }
    
    int next(int price) {
       
        while(!s.empty()&&s.top().first<=price){
            s.pop();
        }
        if(s.empty()){
            s.push({price,i});
            i++;
            return i;
        }else{
            int l=i-s.top().second;
            s.push({price,i});
            i++;
            return l;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */