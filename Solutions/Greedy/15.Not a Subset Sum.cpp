//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long findSmallest(long long arr[], int n) {
        // code here
        long long sum=0;
        long long currCheck=1;
        int i=0;
        while(true){
            while(i<n && arr[i]<=currCheck){
                sum+=arr[i];
                i++;
            }
            if(sum<currCheck){
                break;
            }else{
                currCheck=sum+1;
            }
        }
        return currCheck;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findSmallest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends