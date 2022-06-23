#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> &arr,int &sz){
    for(int i=0;i<sz;i++)cout<<arr[i]<<' ';
    cout<<'\n';
}

void max_heapify(int node,vector<int> &arr,int sz){
    int left=2*node+1,right=2*node+2;
    int largest=node;
    if(left<sz && arr[node]<arr[left]){
        largest=left;
    }
    if(right<sz && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=node){
        swap(arr[node],arr[largest]);
        max_heapify(largest,arr,sz);
    }
}

void heapify(vector<int> &arr,int sz){
    for(int i=sz-1;i>=0;i--){
        max_heapify(i,arr,sz);
    }
}



void heapSort(vector<int> &arr,int &sz){
    heapify(arr,sz);
    int N=sz;
    for(int i=sz-1;i>0;i--){
        swap(arr[0],arr[i]);
        N=N-1;
        max_heapify(0,arr,N);
    }
}
int main(){
    int sz;cin>>sz;
    vector<int> arr(sz);
    for(auto &x:arr)cin>>x;

    print(arr,sz);
    heapSort(arr,sz);
    print(arr,sz);

    return 0;
}