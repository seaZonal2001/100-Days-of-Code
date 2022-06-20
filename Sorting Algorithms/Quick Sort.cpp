/*
    Quick sort is based on divide and conquer approach on the idea of choosing one element as pivot and partioning the array
    around it such that: left side of pivot contains all elements less than pivot and right side contains all elements greater
    than pivot.
    Reduced space complexity and removes the use of auxiliary array.
    Time complexity is improved by selecting pivot at random in most of the cases.

    worst case complexity O(N*N): when array is sorted 
    best case complexity O(NlogN): when pivot element is always the mid element
*/

#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> &arr,int &sz){
    for(int i=0;i<sz;i++)cout<<arr[i]<<' ';
    cout<<'\n';
}
int partition(vector<int> &arr,int low,int high){
    int i=low;
    int j=high;
    int pivot=arr[low];
    while(i<j){
        while(pivot>=arr[i])i++;
        while(pivot<arr[j])j--;
        if(i<j)swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
int randomPartition(vector<int> &arr,int start,int end){
    int random  = start + rand()%(end-start+1);
    swap(arr[start],arr[random]);
    return partition(arr,start,end);
}
void quickSortUtil(vector<int> &arr,int start,int end){
    if(start<end){
        int pivot=randomPartition(arr,start,end);
        quickSortUtil(arr,start,pivot-1);
        quickSortUtil(arr,pivot+1,end);
    }
}
void quickSort(vector<int> &arr,int &sz){
    quickSortUtil(arr,0,sz-1);
}
int main(){
    int sz;cin>>sz;
    vector<int> arr(sz);
    for(auto &x:arr)cin>>x;
    
    print(arr,sz);
    quickSort(arr,sz);
    print(arr,sz);

    return 0;
}