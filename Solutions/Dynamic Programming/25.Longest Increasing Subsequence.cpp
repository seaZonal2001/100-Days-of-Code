#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> LIS;
       LIS.push_back(a[0]);
       
       for(int i=1;i<n;i++){
           auto pos=lower_bound(LIS.begin(),LIS.end(),a[i]);
           if(pos==LIS.end())
            LIS.push_back(a[i]);
           else
            LIS[pos-LIS.begin()]=a[i];
       }
       return (int)LIS.size();
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends