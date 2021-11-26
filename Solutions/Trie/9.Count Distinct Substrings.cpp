class Node{
    private:
    Node *child[26];
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
};
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    Node *root=new Node();
    int cnt=0;
    for(int i=0;i<s.length();i++){
        Node *curr=root;
        for(int j=i;j<s.length();j++){
            if(!curr->containsKey(s[j])){
                curr->put(s[j],new Node());
                cnt++;
            }
            curr=curr->get(s[j]);
        }
    }
    return cnt+1;
}