class Node{
    private:
    Node *child[127];
    bool isEnd=false;
    
    public:
    
    bool containsKey(char ch){
        return child[ch]!=NULL;
    }
    
    void put(char ch,Node *node){
        child[ch]=node;
    }
    
    Node* get(char ch){
        return child[ch];
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
        int n=word.length();
        int i;
        for(i=0;i<n;){
            while(i<n && !curr->containsKey(word[i]) && word[i]>='a' && word[i]<='z')i++;
            if(i<n && !curr->containsKey(word[i]) && word[i]>='A' && word[i]<='Z')break;
            if(i<n)
            curr=curr->get(word[i]),i++;
        }
        return i==n && curr->getEnd();
    }
};
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        Trie *obj=new Trie();
        obj->insert(pattern);
        
        vector<bool> ans;
        
        for(auto query:queries){
            ans.push_back(obj->search(query));
        }
        return ans;
    }
};