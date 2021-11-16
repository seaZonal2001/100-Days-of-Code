#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minDeletions(int arr[], int n) 
	{ 
	    // Your code goes here
	    vector<int> LIS;
	    LIS.push_back(arr[0]);
	    for(int i=1;i<n;i++){
	        if(LIS.back()<arr[i])
	            LIS.push_back(arr[i]);
	        else{
	            int pos=lower_bound(LIS.begin(),LIS.end(),arr[i])-LIS.begin();
	            LIS[pos]=arr[i];
	        }
	            
	    }
	    return n-LIS.size();
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

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

	    

	    Solution ob;
	    cout << ob.minDeletions(arr, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends