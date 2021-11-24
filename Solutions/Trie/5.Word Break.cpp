//*********************************************************Trie Solution***********************************************//
class Solution {
public:
    struct TrieNode{
        TrieNode *children[26];
        bool isEnd;
    };
    TrieNode *root;
    void insert(string &s){
        TrieNode *curr=root;
        for(int i=0;i<s.length();i++){
            int index=s[i]-'a';
            if(curr->children[index]==NULL)
                curr->children[index]=new TrieNode();
            curr=curr->children[index];
        }
        curr->isEnd=true;
    }
   
    bool wordBreak(string s, vector<string>& wordDict) {
        root=new TrieNode();
        for(int i=0;i<wordDict.size();i++)
            insert(wordDict[i]);
        int len=s.length();
        vector<bool> dp(len+1,0);
        dp[0]=true;
        for(int i=0;i<len;i++){
            if(!dp[i])continue;
            TrieNode *curr=root;
            int j=i;
            while(j<len && curr->children[s[j]-'a']){
                curr=curr->children[s[j++]-'a'];
                if(curr->isEnd)dp[j]=true;
            }
            if(dp[len])return true;
        }
        return false;
    }
};

//******************************************************Memoized Solution***************************************************//
class Solution {
public:
    
    vector<int> dp;
    unordered_set<string> lookup;
    int getResult(string &s,int pos){
        if(pos==s.length())return true;
        if(dp[pos]!=-1)return dp[pos];
        for(int i=pos;i<s.length();i++){
            if(lookup.find(s.substr(pos,i-pos+1))!=lookup.end() && getResult(s,i+1))return dp[pos]=1;
        }
        return dp[pos]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        dp.resize(n+1,-1);
        for(auto word:wordDict)lookup.insert(word);
        return getResult(s,0);
    }
};

//********************************************Tabulation*******************************************//
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
        unordered_set<string> lookup;
        for(auto word:wordDict)lookup.insert(word);
        
        for(int length=1;length<=n;length++){
            int start=1,end=length;
            while(end<=n){
                string temp=s.substr(start-1,length);
                if(lookup.find(temp)!=lookup.end())dp[start][end]=true;
                else{
                    bool flag=false;
                    for(int i=start;i<end;i++){
                        if(dp[start][i] && dp[i+1][end]){
                            flag=true;
                            break;
                        }
                    }
                    dp[start][end]=flag;
                }
                start++,end++;
            }
        }
        return dp[1][n];
    }
};