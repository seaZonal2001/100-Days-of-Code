#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n=str1.length(),m=str2.length();
	    vector<vector<int>> LCS(n+1,vector<int>(m+1,0));
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++){
	            if(str1[i-1]==str2[j-1])
	                LCS[i][j]=1+LCS[i-1][j-1];
	            else 
	                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
	        }
	    }
	    int commonCharacters=LCS[n][m];
	    int deletions=n-commonCharacters,insertions=m-commonCharacters;
	    return deletions+insertions;
	    
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends