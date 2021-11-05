class Solution {
public:
    int getResultTD(vector<int>& coins,int n,int amount,vector<vector<int>>& dp){
        if(amount==0)return 1;
        if(amount<0 || n<=0)return 0;
        if(dp[amount][n]!=-1)return dp[amount][n];
        return dp[amount][n]=getResultTD(coins,n,amount-coins[n-1],dp)+getResultTD(coins,n-1,amount,dp);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        //vector<vector<int>> dp(amount+1,vector<int>(n+1,-1));
        //return getResultTD(coins,n,amount,dp);
        
        // vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        // dp[0][0]=1;
        // for(int i=1;i<=n;i++){
        //     dp[i][0]=1;
        //     for(int j=1;j<=amount;j++){
        //         dp[i][j]=dp[i-1][j]+(j>=coins[i-1]?dp[i][j-coins[i-1]]:0);
        //     }
        // }
        // return dp[n][amount];
        
        vector<int> dp(amount+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};