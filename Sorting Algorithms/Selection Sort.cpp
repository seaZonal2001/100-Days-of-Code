/*
    Selection Sort is based on the idea of finding minimum or maximum element in an unsorted array and placing it in
    correct position in sorted array
*/

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &arr,int &sz){
    for(int i=0;i<sz;i++)cout<<arr[i]<<' ';
    cout<<'\n';
}

void selectionSort(vector<int> &arr,int &sz){
    int minimum;
    for(int i=0;i<sz-1;i++){
        minimum=i;                  //finding the element to be placed at i th position
        for(int j=i+1;j<sz;j++){
            if(arr[j]<arr[minimum]){
                minimum=j;
            }
        }
        swap(arr[i],arr[minimum]);  //placing the correct element 
    }
}

int main(){
    int sz;cin>>sz;

    vector<int> arr(sz);
    for(auto &x:arr)cin>>x;

    print(arr,sz);
    selectionSort(arr,sz);
    print(arr,sz);

    return 0;
}