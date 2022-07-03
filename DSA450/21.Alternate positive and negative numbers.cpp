#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    vector<int> pos,neg;
	    for(int i=0;i<n;i++){
	        if(arr[i]>=0)pos.push_back(arr[i]);
	        else neg.push_back(arr[i]);
	    }
	    int sz1=pos.size(),sz2=neg.size();
	    int i=0,j=0;
	    for(int k=0;k<n;k++){
	        if(i<sz1 && j<sz2){
	            if(k&1){
	                arr[k]=neg[j++];
	            }else{
	                arr[k]=pos[i++];
	            }
	        }else if(i<sz1){
	            arr[k]=pos[i++];
	        }else{
	            arr[k]=neg[j++];
	        }
	    }
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends