#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    //Function to return maximum sum subarray by removing at most one element.
    int maxSumSubarray(int A[], int n)
    {
        //Your code here
        vector<int> forwardMaxSum(n,0),backwardMaxSum(n,0);
        forwardMaxSum[0]=A[0],backwardMaxSum[n-1]=A[n-1];
        int maxSoFar=max(A[0],A[n-1]);
        for(int i=1;i<n;i++){
            forwardMaxSum[i]=max(forwardMaxSum[i-1]+A[i],A[i]);
            maxSoFar=max(maxSoFar,forwardMaxSum[i]);
            backwardMaxSum[n-i-1]=max(backwardMaxSum[n-i]+A[n-i-1],A[n-i-1]);
            maxSoFar=max(maxSoFar,backwardMaxSum[n-i-1]);
        }
        for(int i=1;i<n-1;i++){
            maxSoFar=max(maxSoFar,forwardMaxSum[i-1]+backwardMaxSum[i+1]);
        }
        return maxSoFar;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	
	//taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking total elements
		int n;
		cin>>n;
		int a[n];
		
		//inserting elements in the array
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		
		//calling method maxSumSubarray()
		Solution obj;
		cout<<obj.maxSumSubarray(a,n)<<endl;
	}
}

  // } Driver Code Ends