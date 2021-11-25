struct Node{
    Node *children[26];
    bool flag;
    
    bool containsKey(char ch){
        return children[ch-'a']!=NULL;
    }
    
    Node *get(char ch){
        return children[ch-'a'];
    }
    
    void put(char ch,Node *node){
        children[ch-'a']=node;
    }
    
    void setEnd(){
        flag=true;
    }
    
    bool getEnd(){
        return flag;
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
    bool checkIfAllPrefixExist(string &word){
        Node *curr=root;
        bool flag=true;
        for(int i=0;i<word.length();i++){
            if(curr->containsKey(word[i])){
                curr=curr->get(word[i]);
                flag=flag&curr->getEnd();
            }else
                return false;
        }
        return flag;
    }
    
};
class Solution {
public:
    
    string longestWord(vector<string>& words) {
        Trie *obj=new Trie();
        for(auto word:words)obj->insert(word);
        
        string longest="";
        
        for(auto word:words){
            if(obj->checkIfAllPrefixExist(word)){
                if(word.length()>longest.length())
                    longest=word;
                else if(word.length()==longest.length() && word<longest)
                    longest=word;
            }
        }
        return longest;
    }
};