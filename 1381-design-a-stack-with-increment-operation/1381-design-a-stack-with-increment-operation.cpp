class CustomStack {
public:
    vector<int>st;
    vector<int>increments;
    int curr=0;
    int mx=0;
    CustomStack(int maxSize) {
        increments.resize(maxSize,0);
        mx=maxSize;
    }
    
    void push(int x) {
        if(curr==mx){
            return ;
        }
        st.push_back(x);
        curr++;
    }
    int pop() {
        if(curr==0){
            return -1;
        }
        int v=st[curr-1];
        st.erase(st.begin()+curr);
        curr--;
        return v;
    }
    
    void increment(int k, int val) {
        if(curr<=k){
            for(auto &e:st){
                e+=val;
            }
        }else{
            for(int i=0;i<k;i++){
                st[i]+=val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */