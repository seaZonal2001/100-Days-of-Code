#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        int n=s.length();
        const long long MOD=1000000007;
        vector<long long> dp(n,0);
        dp[0]=1;
        long long mul=10;
        for(int i=1;i<n;i++){
            dp[i]=(dp[i-1]+mul)%MOD;
            mul=(mul*10)%MOD;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+(s[i]-'0')*(i+1)*dp[n-i-1])%MOD;
        }
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}
  // } Driver Code Ends