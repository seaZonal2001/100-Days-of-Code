#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    vector<vector<int>> dp(n+1,vector<int>(2,0));
	    dp[1][0]=dp[1][1]=1;
	    
	    for(int i=2;i<=n;i++){
	        dp[i][1]=(dp[i][1]+dp[i-1][0])%1000000007;
	        dp[i][0]=(dp[i][0]+dp[i-1][0]+dp[i-1][1])%1000000007;
	    }
	    return (dp[n][0]+dp[n][1])%1000000007;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends