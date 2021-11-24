class Solution {
public:
    struct TrieNode{
        TrieNode *child[26];
        vector<string> end;
    };
    TrieNode *root;
    void insert(string &s){
        TrieNode *curr=root;
        for(int i=0;i<s.length();i++){
            int index=s[i]-'a';
            if(curr->child[index]==NULL)
                curr->child[index]=new TrieNode();
            curr=curr->child[index];
        }
        curr->end.push_back(s);
    }
    void search(string &s,vector<string> &temp){
        TrieNode *curr=root;
        for(int i=0;i<s.length();i++){
            int index=s[i]-'a';
            if(curr->child[index]==NULL)return ;
            curr=curr->child[index];
        }
        for(auto word:curr->end){
            if(temp.size()==3)
                return;
            temp.push_back(word);
        }
        for(int i=0;i<26;i++){
            if(curr->child[i]!=NULL)
                dfs(curr->child[i],temp);
        }
    }
    void dfs(TrieNode *curr,vector<string> &temp){
        if(temp.size()==3)return ;
        
        for(auto word:curr->end){
            if(temp.size()==3)
                break;
            temp.push_back(word);
        }
        for(int i=0;i<26;i++){
            if(curr->child[i]!=NULL)
                dfs(curr->child[i],temp);
        }
            
        
    }
    vector<vector<string>> ans;
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root=new TrieNode();
        for(int i=0;i<products.size();i++)
            insert(products[i]);
        vector<string> temp;
        string s;
        for(int i=0;i<searchWord.size();i++){
            s+=searchWord[i];
            search(s,temp);
            ans.push_back(temp);
            temp.clear();
        }  
        return ans;
    }
};