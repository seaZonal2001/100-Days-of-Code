class Node{
    private:
    Node *child[26];
    bool isEnd=false;
    
    public:
    bool containsKey(char ch){
        return child[ch-'a']!=NULL;
    }
    
    void put(char ch,Node *node){
        child[ch-'a']=node;
    }
    
    Node* get(char ch){
        return child[ch-'a'];
    }
    
    void setEnd(){
        isEnd=true;
    }
    
    bool getEnd(){
        return isEnd;
    }
};

class Trie{
    private:
    Node *root;
    
    public:
    Trie(){
        root=new Node();
    }
    
    void insert(string &word){
        Node *curr=root;
        for(char c:word){
            if(!curr->containsKey(c)){
                curr->put(c,new Node());
            }
            curr=curr->get(c);
        }
        curr->setEnd();
    }
    
    bool search(string &word){
       Node *curr=root;
       return dfs(curr,word,0,false);
    }
    
    bool dfs(Node *root,string &word,int index,int replaced){
        if(index==word.length())return root->getEnd() && replaced;
        for(char c='a';c<='z';c++){
            if(root->containsKey(c)){
                if(word[index]==c){
                    if(dfs(root->get(c),word,index+1,replaced))
                        return true;
                }else{
                    if(!replaced && dfs(root->get(c),word,index+1,true))
                        return true;
                }
            }
        }
        return false;
        
    }
};
class MagicDictionary {
    Trie *obj;
public:
    MagicDictionary() {
        obj=new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(string word:dictionary){
            obj->insert(word);
        }
    }
    
    bool search(string searchWord) {
        return obj->search(searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */