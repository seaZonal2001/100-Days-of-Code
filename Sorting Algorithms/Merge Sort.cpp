/*
    Merge Sort is a divide and conquer algorithm based on the idea of dividing the list into several sublists until each 
    sublists consists of singlee element and merging those sublist in manner that results in sorted list
*/
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &arr,int &sz){
    for(int i=0;i<sz;i++)cout<<arr[i]<<' ';
    cout<<'\n';
}

void merge(int l,int mid,int r,vector<int> &arr){
    int sz=r-l+1;
    vector<int> tarr(sz);
    int i=l,j=mid+1;
    for(int k=0;k<sz;k++){
        if(i<=mid && j<=r){
            if(arr[i]<=arr[j])tarr[k]=arr[i++];
            else tarr[k]=arr[j++];
        }else if(i<=mid){
            tarr[k]=arr[i++];
        }else{
            tarr[k]=arr[j++];
        }
    }
    for(int k=l;k<=r;k++)arr[k]=tarr[k-l];
}

void mergeSortUtil(int l,int r,vector<int> &arr){
    if(l<r){
        int mid=(l+r)>>1;
        mergeSortUtil(l,mid,arr);           //left half
        mergeSortUtil(mid+1,r,arr);         //right half

        merge(l,mid,r,arr);                 //merge the left and right half
    }
}

void mergeSort(vector<int> &arr,int &sz){
    mergeSortUtil(0,sz-1,arr);
}

int main(){
    int sz;cin>>sz;
    vector<int> arr(sz);
    for(auto &x:arr)cin>>x;

    print(arr,sz);
    mergeSort(arr,sz);
    print(arr,sz);

    return 0;
}