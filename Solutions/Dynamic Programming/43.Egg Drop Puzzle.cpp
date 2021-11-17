#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int eggDrop(int e, int f) 
    {
        // your code here
        if(e==1 || f==0 || f==1)return f;
        if(dp[e][f]!=-1)return dp[e][f];
        int ans=INT_MAX;
        for(int x=1;x<=f;x++){
           int temp=1+max(eggDrop(e-1,x-1),eggDrop(e,f-x));
           ans=min(ans,temp);
        }
        return dp[e][f]=ans;
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends