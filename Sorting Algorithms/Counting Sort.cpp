/*
    In counting sort , the frequencies of distinct elements to be sorted is counted and stored in auxiliary array,by mapping 
    its value as index of auxiliary array.
    Can be applied only when (max_element-min_element)<=10^6
*/

#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> &arr,int &sz){
    for(int i=0;i<sz;i++)cout<<arr[i]<<' ';
    cout<<'\n';
}

void countingSort(vector<int> &arr,int &sz){
    int mx_ele=INT32_MIN;
    int mn_ele=INT32_MAX;

    for(int i=0;i<sz;i++){
        mx_ele=max(mx_ele,arr[i]);
        mn_ele=min(mn_ele,arr[i]);
    }

    int K=mx_ele-mn_ele+1;
    vector<int> freq(K,0);
    for(int i=0;i<sz;i++){
        freq[arr[i]-mn_ele]++;
    }

    vector<int> sorted(sz);
    int l=0;
    for(int i=0;i<K;i++){
        for(int j=0;j<freq[i];j++){
            sorted[l++]=i+mn_ele;
        }
    }

    for(int i=0;i<sz;i++)arr[i]=sorted[i];
}
int main(){
    int sz;cin>>sz;
    vector<int> arr(sz);
    for(auto &x:arr)cin>>x;

    print(arr,sz);
    countingSort(arr,sz);
    print(arr,sz);

    return 0;
}