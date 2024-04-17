class LRUCache {
public:
    list<int>l;
    map<int,pair<list<int>::iterator,int>>mp;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    void recentlyUsed(int key){
        l.erase(mp[key].first);
        l.push_front(key);
        mp[key].first=l.begin();
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            recentlyUsed(key);
            return mp[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key].second=value;
            recentlyUsed(key);
        }
        else{
        l.push_front(key);
        mp[key]={l.begin(),value};
            n--;
        }
        if(n<0){
            int d=l.back();
            mp.erase(d);
            l.pop_back();
            n++;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */