#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(int l,int mid,int r,long long arr[]){
        int n=(r-l+1);
        long long c[n];
        int i=l,j=mid+1;
        long long inversions=0;
        for(int k=0;k<n;k++){
            if(i<=mid && j<=r){
                if(arr[i]<=arr[j]){
                    c[k]=arr[i++];
                }else{
                    inversions+=(mid-i+1);
                    c[k]=arr[j++];
                }
            }else if(i<=mid){
                c[k]=arr[i++];
            }else{
                c[k]=arr[j++];
            }
        }
        for(int k=0;k<n;k++)arr[l+k]=c[k];
        return inversions;
    }
    long long mergeSort(int l,int r,long long arr[]){
        long long inversions=0;
        if(l<r){
            int mid=(l+r)>>1;
            inversions+=mergeSort(l,mid,arr);
            inversions+=mergeSort(mid+1,r,arr);
            inversions+=merge(l,mid,r,arr);
        }
        return inversions;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(0,N-1,arr);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends