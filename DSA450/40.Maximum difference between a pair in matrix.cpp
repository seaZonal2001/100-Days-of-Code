/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int findMaxValue(vector<vector<int>>&mat, int N)
    {
        int maxVal=INT_MIN;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i>0 && j>0)maxVal=max(maxVal,mat[i][j]-mat[i-1][j-1]);
                if(j>0)mat[i][j]=min(mat[i][j],mat[i][j-1]);
                if(i>0)mat[i][j]=min(mat[i][j],mat[i-1][j]);
            }
        }
        
        return maxVal;
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
	    cin >> n;
	    vector<vector<int>>mat(n,vector<int>(n, 0));
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            cin >> mat[i][j];
	        }
	    }
	    Solution ob;
	    int ans = ob.findMaxValue(mat, n);
	    cout << ans <<endl;
	}
	return 0;
}
  // } Driver Code Ends