class Solution {
public:
    void generateSubsets(int curr,int k,int n,vector<int>& temp,vector<vector<int>>& ans){
        if(n==0 && k==0){
            ans.push_back(temp);
            return;
        }
        if(k==0 || curr==10 || n<0)return ;
        generateSubsets(curr+1,k,n,temp,ans);
        temp.push_back(curr);
        generateSubsets(curr+1,k-1,n-curr,temp,ans);
        temp.pop_back();
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        generateSubsets(1,k,n,temp,ans);
        return ans;
    }
};