class Solution {
public:
    void generateSubsets(vector<int>& candidates,int id,int target,vector<int>& temp,vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        
        for(int i=id;i<candidates.size();i++){
            if(i>id && candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            temp.push_back(candidates[i]);
            generateSubsets(candidates,i+1,target-candidates[i],temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        generateSubsets(candidates,0,target,temp,ans);
        return ans;
    }
};