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
        for(int i=0;i<word.length();i++){
            if(!curr->containsKey(word[i])){
                curr->put(word[i],new Node());
            }
            curr=curr->get(word[i]);
        }
        curr->setEnd();
    }
    
    string search(string &word){
        Node *curr=root;
        string prefixMatch="";
        for(int i=0;i<word.length();i++){
            if(!curr->containsKey(word[i])){
                return word;
            }
            prefixMatch+=word[i];
            curr=curr->get(word[i]);
            if(curr->getEnd()==true){
                break;
            }
        }
        return prefixMatch;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie *obj=new Trie();
        for(auto word:dictionary){
            obj->insert(word);
        }
        string ans="",temp="";
        for(int i=0;i<sentence.length();i++){
            if(sentence[i]==' '){
                ans+=" "+obj->search(temp);
                temp.clear();
            }else{
                temp+=sentence[i];
            }
        }
        ans+=" "+obj->search(temp);
        return ans.substr(1);
        
    }
};