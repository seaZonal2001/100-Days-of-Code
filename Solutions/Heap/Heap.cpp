#include<bits/stdc++.h>
using namespace std;
class MinHeap{
    int *arr;
    int size;
    int capacity;
    public:
    MinHeap(int c):arr(new int[c]),size(0),capacity(c){};
    int left(int i){return i*2+1;}
    int right(int i){return i*2+2;}
    int parent(int i){return (i-1)/2;}
    void push(int val);
    void decreaseKey(int i,int new_val);
    int pop();
    void deleteKey(int i);
    int top(){return arr[0];}
    void heapify(int );
};
void MinHeap::push(int val){
    if(size==capacity)return;
    size++;
    arr[size-1]=val;
    for(int i=size-1;i!=0 && arr[parent(i)]>arr[i];){
        swap(arr[i],arr[parent(i)]);
        i=parent(i);
    }
}
void MinHeap::heapify(int i){
    int lt=left(i),rt=right(i);
    int smallest=i;
    if(lt<size && arr[lt]<arr[smallest])
    smallest=lt;
    if(rt<size && arr[rt]<arr[smallest])
    smallest=rt;
    if(smallest!=i){
        swap(arr[i],arr[smallest]);
        heapify(smallest);
    }
}
int MinHeap::pop(){
    if(size==0)return INT_MAX;
    if(size==1){
        size--;
        return arr[0];
    }
    swap(arr[0],arr[size-1]);
    size--;
    heapify(0);
    return arr[size];
}
void MinHeap::decreaseKey(int i,int new_val){
    arr[i]=new_val;
    while(i!=0 && arr[parent(i)]>arr[i]){
        swap(arr[i],arr[parent(i)]);
        i=parent(i);
    }
}
void MinHeap::deleteKey(int i){
    decreaseKey(i,INT_MIN);
    pop();

}
int main(){
    MinHeap h(11);
    h.push(2);
    h.push(10);
    h.push(15);
    cout<<h.pop()<<'\n';
    cout<<h.top()<<'\n';
}