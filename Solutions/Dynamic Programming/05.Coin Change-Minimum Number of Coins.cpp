#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:

	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	   
	    vector<int> dp(V+1,0);
	    for(int i=1;i<=V;i++){
	        dp[i]=INT_MAX-1;
	        for(int j=0;j<M;j++){
	            if(i-coins[j]>=0){
	                dp[i]=min(dp[i],dp[i-coins[j]]+1);
	            }
	        }
	    }
	    return dp[V]==INT_MAX-1?-1:dp[V];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends