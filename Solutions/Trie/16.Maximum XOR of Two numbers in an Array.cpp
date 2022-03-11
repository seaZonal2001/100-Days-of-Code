const int N=30;
class Node{
    private:
    Node *child[2];
    
    public:
    
    bool containsKey(int x){
        return child[x]!=NULL;
    }
    
    void put(int x,Node *node){
        child[x]=node;
    }
    
    Node* get(int x){
        return child[x];
    }
};

class BinaryTrie{
    private:
    Node *root;
    
    public:
    BinaryTrie(){
        root=new Node();
    }
    
    void insert(int &num){
        Node *curr=root;
        int x;
        for(int i=N;i>=0;i--){
            x=(num>>i)&1;
            if(!curr->containsKey(x)){
                curr->put(x,new Node());
            }
            curr=curr->get(x);
        }
    }
    int search(int &num){
        Node *curr=root;
        int x,ans=0;
        for(int i=N;i>=0;i--){
            x=(num>>i)&1;
            if(curr->containsKey(x^1)){
                ans|=(1<<i);
                curr=curr->get(x^1);
            }else{
                curr=curr->get(x);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        BinaryTrie *obj=new BinaryTrie();
        for(int i=0;i<n;i++){
            obj->insert(nums[i]);
             ans=max(ans,obj->search(nums[i]));
        }
        return ans;
    }
};