struct Node{
    Node* arr[26];
    int countPrefix=0;
    int countEnd=0;
};
class Trie{
    Node* root;
    public:
      Trie(){
          root =new Node();
      }
    void insert(string &s){
       int n=s.size();
        Node *node=root;
        for(int i=0;i<n;i++){
            if(node->arr[s[i]-'a']==NULL){
                node->arr[s[i]-'a']=new Node();
            }
            node=node->arr[s[i]-'a'];
            node->countPrefix++;
        }
        node->countEnd++;
    }
    int noOfString(string &s){
        int n=s.size();
        Node* node=root;
        for(int i=0;i<n;i++){
            if(node->arr[s[i]-'a']==NULL){
                return 0;
            }
            node=node->arr[s[i]-'a'];
        }
        return node->countEnd;
    }
    int NoOfStringPrefix(string &s){
        int n=s.size();
        Node* node=root;
        int count=0;
        for(int i=0;i<n;i++){
          if(node->arr[s[i]-'a']==NULL){
              return 0;
          }  
            node=node->arr[s[i]-'a'];
            count+=(node->countPrefix);
        }
        return count;
    }
    void remove(string &s){
        int n=s.size();
        Node* node=root;
        for(int i=0;i<n;i++){
            node=node->arr[s[i]-'a'];
            node->countPrefix--;
        }
        node->countEnd--;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie t;
        int n=words.size();
        for(auto w:words){
            t.insert(w);
        }
         vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=t.NoOfStringPrefix(words[i]);
        }
        return ans;
    }
};