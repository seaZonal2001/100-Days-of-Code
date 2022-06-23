/*
    Insertion sort is based on the idea that in each iteration an element is consumed and placed at correct position in sorted array
    This ensures that at start of each iteration(i) all elements upto (i-1)th index is sorted.
*/
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &arr,int &sz){
    for(int i=0;i<sz;i++)cout<<arr[i]<<' ';
    cout<<'\n';
}

void insertionSort(vector<int> &arr,int &sz){

    for(int i=0;i<sz;i++){
        int temp=arr[i];
        int j=i;
        
        while(j>0 && temp<arr[j-1]){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=temp;
    }
}

int main(){
    int sz;cin>>sz;
    vector<int> arr(sz);
    for(auto &x:arr)cin>>x;

    print(arr,sz);
    insertionSort(arr,sz);
    print(arr,sz);

    return 0;
}