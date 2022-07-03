#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        //O(N) time and space 
      /*  vector<int> lMax(n),rMax(n);
        lMax[0]=arr[0];
        for(int i=1;i<n;i++){
            lMax[i]=max(lMax[i-1],arr[i]);
        }
        rMax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            rMax[i]=max(rMax[i+1],arr[i]);
        }
        
        long long maxUnits=0;
        for(int i=0;i<n;i++){
            maxUnits+=(min(lMax[i],rMax[i])-arr[i]);
        }
        
        return maxUnits;
        
      */
      
      //O(N) time and O(1) space
      
      int l=0,r=n-1;
      int leftMax=0,rightMax=0;
      long long maxUnits=0;
      
      while(l<=r){
          if(arr[l]<=arr[r]){
              if(arr[l]>leftMax){
                  leftMax=arr[l];
              }else{
                  maxUnits+=(leftMax-arr[l]);
              }
              l++;
          }else{
              if(arr[r]>rightMax){
                  rightMax=arr[r];
              }else{
                  maxUnits+=(rightMax-arr[r]);
              }
              r--;
          }
      }
     
      return maxUnits;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends