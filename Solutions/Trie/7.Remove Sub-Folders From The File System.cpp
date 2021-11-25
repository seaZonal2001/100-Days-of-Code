struct Node{
    unordered_map<char,Node*> children;
    bool flag=false;
    
    bool containsKey(char ch){
        return children.find(ch)!=children.end();
    }
    
    Node* get(char ch){
        return children[ch];
    }
    
    void put(char ch,Node *node){
        children[ch]=node;
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
    bool insert(string &word){
        Node *curr=root;
        bool flag=false;
        for(int i=0;i<word.length();i++){
           
            if(!curr->containsKey(word[i])){
                curr->put(word[i],new Node());
                flag=true;
            }
            curr=curr->get(word[i]);
            if(word[i+1]=='/' && curr->getEnd())return false;
        }
        curr->setEnd();
        return flag;
    }
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        Trie *obj=new Trie();
        vector<string> ans;
        for(auto e:folder){
            if(obj->insert(e)){
                ans.push_back(e);
            }
        }
        return ans;
    }
};