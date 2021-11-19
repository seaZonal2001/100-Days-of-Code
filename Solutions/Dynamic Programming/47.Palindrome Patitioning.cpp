// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string s)
    {
        // code here
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        vector<vector<bool>> isPalindrome(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
            dp[i][i]=0,isPalindrome[i][i]=true;
        
        for(int gap=1;gap<n;gap++){
            for(int i=0;i+gap<n;i++){
                int j=i+gap;
                if(s[i]==s[j] && (j-i<=2 ||isPalindrome[i+1][j-1])){
                    dp[i][j]=0;
                    isPalindrome[i][j]=true;
                }else{
                    isPalindrome[i][j]=false;
                    dp[i][j]=INT_MAX;
                    for(int k=i;k<j;k++){
                        dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[k+1][j]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends