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
    
    void unsetEnd(){
        isEnd=false;
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
        bool flag=false;
        for(int i=word.length()-1;i>=0;i--){
            curr->unsetEnd();
            if(!curr->containsKey(word[i])){
                flag=true;
                curr->put(word[i],new Node());
            }
            curr=curr->get(word[i]);
        }
        if(flag)
            curr->setEnd();
    }
    bool search(string &word){
        Node *curr=root;
        for(int i=word.length()-1;i>=0;i--){
            curr=curr->get(word[i]);
        }
        return curr->getEnd();
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie *obj=new Trie();
        int ans=0;
        for(auto word:words){
            obj->insert(word);
        }
        set<string> hash;
        for(auto word:words){
            if(obj->search(word)){
                hash.insert(word);
            }
        }
        for(auto word:hash)
            ans+=word.length()+1;
        return ans;
    }
};