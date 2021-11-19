class Solution {
public:
    int getResult(vector<int>& nums,int i,int j,vector<vector<int>>& dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        for(int k=i;k<=j;k++){
            dp[i][j]=max(dp[i][j],getResult(nums,i,k-1,dp)+getResult(nums,k+1,j,dp)+nums[i-1]*nums[k]*nums[j+1]);
        }
        return dp[i][j];
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return getResult(nums,1,n-2,dp);
    }
};