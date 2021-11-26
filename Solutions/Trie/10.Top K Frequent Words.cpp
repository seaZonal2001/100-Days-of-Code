//*************************************Trie Solution*********************************************//
class Solution {
    struct Trie {
        int Cnt;
        int Id;
        Trie* Next[26];
    };

    Trie* New() {
        Trie* Node = new Trie();
        Node->Cnt = 0;
        Node->Id = -1;
        for (int i = 0; i < 26; ++i) {
            Node->Next[i] = NULL;
        }
        return Node;
    }
    
    Trie* Root = New();
    void Insert(string& s, int& Id) {
        Trie* Node = Root;
        for (auto& c : s) {
            if (Node->Next[c - 'a'] == NULL) {
                Node->Next[c - 'a'] = New();
            }
            Node = Node->Next[c - 'a'];
        }
        ++Node->Cnt;
        Node->Id = Id;
    }
    
    void Dfs(Trie* Node, vector<vector<int>>& freq) {
        if (Node != NULL) {
            if (Node->Id != -1) {
                freq[Node->Cnt].push_back(Node->Id);
            }
            for (int i = 0; i < 26; ++i) {
                Dfs(Node->Next[i], freq);
            }
        }
    }
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<vector<int>> freq(words.size() + 1, vector<int>());
        for (int i = 0; i < (int)words.size(); ++i) {
            Insert(words[i], i);
        }
        Dfs(Root, freq);
        vector<string> ans;
        for (int i = (int)words.size(); i >= 0 && k > 0; --i) {
            for (auto& Id : freq[i]) {
                ans.push_back(words[Id]);
                --k;
                if (k == 0) {
                    break;
                }
            }
        }
        return ans;
    }
};


//************************************************Priority Queue Solution************************************************//
class Solution {
public:
    struct myComp{
      bool operator()(pair<string,int> &a,pair<string,int> &b){
          if(a.second==b.second)return a.first<b.first; //creates lexi largest heap 
          
          return a.second>b.second; //creates min heap wrt frequency
      }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> hash;
        for(auto word:words)hash[word]++;
        
        priority_queue<pair<string,int>,vector<pair<string,int>>,myComp> pq;
        for(auto i:hash){
            pq.push({i.first,i.second});
            if(pq.size()>k)pq.pop();
        }
        vector<string> ans(k);
        int i=k-1;
        while(!pq.empty())
            ans[i--]=pq.top().first,pq.pop();
        return ans;
    }
};