
class TrieNode{
    public:
       map<char,TrieNode*>child;
       bool endWord;
       TrieNode(){
          endWord=false;
       }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
       this->root=new TrieNode(); 
    }
    
    void insert(string word) {
        TrieNode* node=root;
        for(auto c:word){
            if(node->child.count(c)==0){
                TrieNode* nN=new TrieNode();
                node->child[c]=nN;
            }
            node=node->child[c];
        }
        node->endWord=true;
    }
    
    bool search(string word) {
        TrieNode* curr=root;
        for(auto c:word){
            if(curr->child.count(c)==0){
                return false;
            }
            curr=curr->child[c];
        }
        return curr->endWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr=root;
        for(auto c:prefix){
            if(curr->child.count(c)==0){
                return false;
            }
            curr=curr->child[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */