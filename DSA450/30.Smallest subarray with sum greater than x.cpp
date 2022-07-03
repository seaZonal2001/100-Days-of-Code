#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int curr_sum=0;
        int l=-1;
        int mnLen=INT_MAX;
        
        for(int r=0;r<n;r++){
            curr_sum+=arr[r];
            while(curr_sum>x){
                mnLen=min(mnLen,r-l);
                curr_sum-=arr[++l];
            }
        }
        return mnLen;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends