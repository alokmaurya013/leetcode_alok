class Trie {
public:
    bool terminal;
    Trie* next[26]; 

    Trie() {
        terminal = false;
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};
class Solution {
public:
    Trie* root=new Trie();
    void insert(string word){
       Trie* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->next[index]) {
                curr->next[index] = new Trie();
            }
            curr = curr->next[index];
        }
        curr->terminal = true; 
    }
    string search(string word){
        Trie* curr = root;
        string res="";
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            int index = c - 'a';
            if (!curr->next[index]) {
                return word; 
            }
            res+=c;;
            if (curr->next[index]->terminal) {
                return res;
            }
            curr=curr->next[index];
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(auto s:dictionary){
            insert(s);
        }
          stringstream ss(sentence);
        string word, res;
        while (ss >> word) {
            if (!res.empty()) {
                res+= " ";
            }
            res+= search(word);
        } 
         return res;
    }
};