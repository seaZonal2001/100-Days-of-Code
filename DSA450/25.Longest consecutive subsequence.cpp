#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      vector<bool> present(100001,false);
      for(int i=0;i<N;i++)present[arr[i]]=true;
      int maxLen=0;
      int len=0;
      
      for(int i=0;i<100001;i++){
          if(!present[i]){
              len=0;
          }else{
              len++;
          }
          maxLen=max(maxLen,len);
      }
      
      return maxLen;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends