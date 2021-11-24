class Solution {
public:
    struct TrieNode{
        TrieNode *children[10];
        bool isEnd;
    };
    TrieNode *root;
    void insert(string &s){
        TrieNode *curr=root;
        for(int i=0;i<s.length();i++){
            int index=s[i]-'0';
            if(curr->children[index]==NULL)
                curr->children[index]=new TrieNode();
            curr=curr->children[index];
        }
        curr->isEnd=true;
    }
    void dfs(TrieNode *curr,string num,vector<int> &ans){
        if(curr->isEnd)ans.push_back(stoi(num));
        for(int i=0;i<10;i++){
            if(curr->children[i]!=NULL){
                num+=(char)(i+'0');
                dfs(curr->children[i],num,ans);
                num.pop_back();
            }
                
        }
        
    }
    vector<int> lexicalOrder(int n) {
        root=new TrieNode();
        for(int i=1;i<=n;i++){
            string num=to_string(i);
            insert(num);
        }
        vector<int> ans;
        string num;
        dfs(root,num,ans);
        return ans;
    }
};