//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    int partition(int arr[],int l,int r){
        int i=l-1;
        int pivot=arr[r];
        for(int j=l;j<r;j++){
            if(arr[j]<pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[r]);
        return i+1;
    }
    int randomPartition(int arr[],int l,int r){
        int random= l + rand()%(r-l+1);
        swap(arr[random],arr[r]);
        return partition(arr,l,r);
    }
    int quickSelect(int arr[],int l,int r,int k){
        int pivot=-1;
        while(pivot!=k){
            pivot=randomPartition(arr,l,r);
            if(pivot>k)r=pivot-1;
            else if(pivot<k)l=pivot+1;
        }
        return pivot;
    }
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        return arr[quickSelect(arr,l,r,k-1)];
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends