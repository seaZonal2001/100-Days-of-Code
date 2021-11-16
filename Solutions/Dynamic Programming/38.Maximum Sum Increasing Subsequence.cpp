#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> MSIS(n,0);
	    for(int i=0;i<n;i++){
	        MSIS[i]=arr[i];
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i])
	                MSIS[i]=max(MSIS[i],MSIS[j]+arr[i]);
	        }
	    }
	    return *max_element(MSIS.begin(),MSIS.end());
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends