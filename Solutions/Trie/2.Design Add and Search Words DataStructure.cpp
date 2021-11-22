class WordDictionary {
    class TrieNode{
        public:
        TrieNode *children[26];
        bool isEnd;
        bool find(string& word,int i){
            if(i==word.length())
                return isEnd;
            if(word[i]=='.'){
                for(auto child:children){
                    if(child!=NULL && child->find(word,i+1))return true;
                }
                return false;
            }else{
                int index=word[i]-'a';
                if(children[index]==NULL)return false;
                else return children[index]->find(word,i+1);
            }
        }
    };
    TrieNode *root;
public:
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *curr=root;
        for(int i=0;i<word.length();i++){
            int index=word[i]-'a';
            if(curr->children[index]==NULL)
                curr->children[index]=new TrieNode();
            curr=curr->children[index];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        return root->find(word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */