#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        // vector<int> dp(n+1,0);
        // dp[0]=dp[1]=1;
        // for(int i=2;i<=n;i++)
        // dp[i]=(dp[i-1]+1LL*(i-1)*dp[i-2])%1000000007;
        // return dp[n];
        int a=1,b=1,c=1;
        for(int i=2;i<=n;i++){
            c=(b+1LL*(i-1)*a)%1000000007;
            a=b;
            b=c;
        }
        return c;
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends