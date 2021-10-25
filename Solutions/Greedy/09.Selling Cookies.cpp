#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n;cin>>n;
    vector<int> arr(n);
    long long sum=0;
    for(auto &i:arr)cin>>i,sum+=i;
    sort(arr.begin(),arr.end());
    sum-=arr[n-1];
    if(arr[n-1]>=sum){
        cout<<arr[n-1]-sum<<'\n';
    }else{
        cout<<(sum+arr[n-1])%2<<'\n';
    }
}
int main(){
    int testCase;cin>>testCase;
    while(testCase--){
        solution();
    }
}