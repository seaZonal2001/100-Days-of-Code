/* 
    Bubble sort is based on the idea of repeatedly comparing pair of adjacent elements and then 
    swapping their positions if they exist in wrong order
*/

#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> &arr,int &sz){
    for(int i=0;i<sz;i++)cout<<arr[i]<<' ';
    cout<<'\n';
}

void bubbleSort(vector<int> &arr,int &sz){

    bool flag;
    for(int i=0;i<sz-1;i++){        //if sz-1 elements are placed at correct position then last element will definitely be in correct position 
        flag=false;
        for(int j=0;j<sz-i-1;j++){  //if i elements are already in correct position then no need to operate over them  
            if(arr[j]>arr[j+1]){
                flag=true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(!flag)break;             //no swap performed in this iteration mean all elements are in correct position
    }
}

int main(){
    int sz;cin>>sz;

    vector<int> arr(sz);
    for(auto &x:arr)cin>>x;

    print(arr,sz);
    bubbleSort(arr,sz);
    print(arr,sz);

    return 0;
}