// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool allocate(int limit,int A[],int N,int M){
        long long studCnt=1,pages=0;
        for(int i=0;i<N;i++){
            if(A[i]>limit)return false;
            if(A[i]+pages>limit){
                studCnt++;
                pages=A[i];
            }else{
                pages+=A[i];
            }
        }
        return studCnt<=M;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        long long low=0,high=0,mid;
        for(int i=0;i<N;i++)high+=A[i];
        
        while(low<=high){
            mid=(high-low)/2+low;
            if(allocate(mid,A,N,M))
                high=mid-1;
            else
                low=mid+1;
        }
        return (int)low;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends