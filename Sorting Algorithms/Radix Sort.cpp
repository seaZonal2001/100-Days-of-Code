#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(vector<int> &arr,int &sz){
    for(int i=0;i<sz;i++)cout<<arr[i]<<' ';
    cout<<'\n';
}

void countSort(vector<int> &arr,int &sz,int &exp){
    vector<int> freq(10,0),sorted(sz);

    for(auto &x:arr)freq[(x/exp)%10]++;
    for(int i=1;i<10;i++)freq[i]+=freq[i-1];

    for(int i=sz-1;i>=0;i--){
        sorted[freq[(arr[i]/exp)%10]-1]=arr[i];
        freq[(arr[i]/exp)%10]--;
    }

    for(int i=0;i<sz;i++){
        arr[i]=sorted[i];
    }
}

void radixSort(vector<int> &arr,int &sz){
    int mxEl=*max_element(arr.begin(),arr.end());
    int exp=1;

    while(mxEl){
        countSort(arr,sz,exp);
        exp*=10;
        mxEl/=10;
    }
}
int main(){
    int sz;cin>>sz;
    vector<int> arr(sz);
    for(auto &x:arr)cin>>x;

    print(arr,sz);
    radixSort(arr,sz);
    print(arr,sz);

    return 0;
}