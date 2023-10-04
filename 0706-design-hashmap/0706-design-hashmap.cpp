class MyHashMap {
public:
    vector<pair<int,int>>a[1024];
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int bucket=key%(sizeof(a)/sizeof(a[0]));
  int len=a[bucket].size();
  int i;
  for(i=0;i<len;i++){
    if(a[bucket][i].first==key){
      a[bucket][i].second=value;
      break;
    }
  }
  if(i==len){
    a[bucket].push_back({key,value});
  } 
    }
    
    int get(int key) {
         int bucket=key%(sizeof(a)/sizeof(a[0]));
   int len=a[bucket].size();
   for(int i=0;i<len;i++){
    if(a[bucket][i].first==key){
      return a[bucket][i].second;
    }
   }
   return -1;
        
    }
    
    void remove(int key) {
         int bucket=key%(sizeof(a)/sizeof(a[0]));
  int len=a[bucket].size();
  for(int i=0;i<len;i++){
    if(a[bucket][i].first==key){
      a[bucket].erase(a[bucket].begin()+i);
      break;
    }
  } 
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */