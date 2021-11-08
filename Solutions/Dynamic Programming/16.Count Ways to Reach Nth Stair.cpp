#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int getResult(int n,vector<int>& dp){
        if(n==0)return 1;
        
        if(dp[n]!=0)return dp[n];
        for(int i=1;i<=2;i++)
        if(n-i>=0)
            dp[n]=(dp[n]+getResult(n-i,dp))%1000000007;
        return dp[n];
    }
    int countWays(int n)
    {
        // your code here
        vector<int> dp(n+1,0);
        //Top Down
        //return getResult(n,dp);

        //Bottom Up
        dp[0]=1;
        for(int i=1;i<=n;i++){
           for(int j=1;j<=2;j++)
            if(i-j>=0)
                dp[i]=(dp[i]+dp[i-j])%1000000007;
        }
        return dp[n];
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends