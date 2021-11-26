// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++
struct Node{
    Node *children[26];
    int end=0,first=-1;
    bool containsKey(char ch){
        return children[ch-'a']!=NULL;
    }
    Node* get(char ch){
        return children[ch-'a'];
    }
    void put(char ch,Node *node){
        children[ch-'a']=node;
    }
    void incEnd(){
        end++;
    }
    int getEnd(){
        return end;
    }
    void setFirst(int i){
        first=i;
    }
    int getFirst(){
        return first;
    }
};

class Trie{
    private:
    Node *root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string &word,int i){
        Node *curr=root;
        for(int i=0;i<word.length();i++){
            if(!curr->containsKey(word[i]))
                curr->put(word[i],new Node());
            curr=curr->get(word[i]);
        }
        if(!curr->getEnd())
            curr->setFirst(i);
        curr->incEnd();
    }
    pair<int,int> search(string &word){
        Node *curr=root;
        for(auto c:word){
            curr=curr->get(c);
        }
        return {curr->getEnd(),curr->getFirst()};
    }
};
class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        // code here
        Trie *obj=new Trie();
        for(int i=0;i<n;i++)
            obj->insert(arr[i],i);
        string ans="";
        int freq=0,fo=-1;
        for(int i=0;i<n;i++){
            auto temp=obj->search(arr[i]);
            if(freq<temp.first){
                freq=temp.first;
                fo=temp.second;
                ans=arr[i];
            }else if(freq==temp.first && fo<temp.second){
                ans=arr[i];
                fo=temp.second;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends