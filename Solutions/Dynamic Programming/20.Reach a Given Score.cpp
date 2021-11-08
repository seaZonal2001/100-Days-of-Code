// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
long long int count(long long int n)
{
    vector<int> move={3,5,10};
    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int i=0;i<3;i++){
        for(int j=move[i];j<=n;j++)
            dp[j]+=dp[j-move[i]];
    }
    return dp[n];
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends