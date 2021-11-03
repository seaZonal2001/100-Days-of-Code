#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    long long int topDown(long long int n,vector<long long>& dp){
        if(n==0 || n==1)return n;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=(topDown(n-1,dp)+topDown(n-2,dp))%1000000007;
    }
    long long int nthFibonacci(long long int n){
        // code here
        vector<long long> dp(n+1,-1);
        return topDown(n,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends