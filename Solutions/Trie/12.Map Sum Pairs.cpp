class Node{
    private:
    Node *child[26];
    int value=0;
    
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
    
    void setValue(int val){
        value=val;
    }
    
    int getValue(){
        return value;
    }
};

class Trie{
    private:
    Node *root;
    
    public:
    
    Trie(){
        root=new Node();
    }
    
    void insert(string &word,int &val){
        Node *curr=root;
        
        for(int i=0;i<word.length();i++){
            if(!curr->containsKey(word[i])){
                curr->put(word[i],new Node());
            }
            curr=curr->get(word[i]);
        }
        curr->setValue(val);
    }
    int search(string &word){
        Node *curr=root;
        int sum=0;
        for(int i=0;i<word.length();i++){
            if(!curr->containsKey(word[i])){
                return 0;
            }
            curr=curr->get(word[i]);
        }
        
        dfs(curr,sum);
        return sum;
    }
    void dfs(Node *curr,int &sum){
        sum+=curr->getValue();
        for(int i=0;i<26;i++){
            if(curr->containsKey((char)(i+'a'))){
                dfs(curr->get((char)(i+'a')),sum);
            }
        }
    }
};
class MapSum {
    Trie *obj;
public:
    MapSum() {
        obj=new Trie();
    }
    
    void insert(string key, int val) {
        obj->insert(key,val);
    }
    
    int sum(string prefix) {
        return obj->search(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */