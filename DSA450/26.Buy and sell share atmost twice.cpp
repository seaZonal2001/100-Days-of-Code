class Solution {
    //top down approach
    int dp[100001][2][3];
    int helper(int i,bool buy,int cap,int &n,vector<int> &prices){
        if(i==n || cap==0)return 0;
        if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
        if(buy){
            return dp[i][buy][cap]=max(-prices[i]+helper(i+1,!buy,cap,n,prices),0+helper(i+1,buy,cap,n,prices));
        }
        return dp[i][buy][cap]=max(prices[i]+helper(i+1,!buy,cap-1,n,prices),0+helper(i+1,buy,cap,n,prices));
    }
    
    //bottom up approach
    int helper(vector<int> &prices,int n){
        memset(dp,0,sizeof(dp));
        
        for(int i=n-1;i>=0;i--){
            for(int buy=1;buy>=0;buy--){
                for(int cap=1;cap<=2;cap++){
                    if(buy)
                        dp[i][buy][cap]=max(-prices[i]+dp[i+1][1-buy][cap],dp[i+1][buy][cap]);
                    else
                        dp[i][buy][cap]=max(prices[i]+dp[i+1][1-buy][cap-1],dp[i+1][buy][cap]);
                }
            }
        }
        return dp[0][1][2];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        //memset(dp,-1,sizeof(dp));
        //return helper(0,1,2,n,prices);
        
        return helper(prices,n);
        
    }
};