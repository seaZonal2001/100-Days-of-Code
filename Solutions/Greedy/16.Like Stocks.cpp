#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    for(auto &i:arr)cin>>i;
    long long mx_sum=0;
    int t_sum=0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1])
        t_sum+=(arr[i]-arr[i-1]);
        else{
            if(t_sum>k){
                mx_sum+=t_sum-k;
                t_sum=0;
            }
        }
    }
    if(t_sum && t_sum>k){
        mx_sum+=t_sum-k;
    }
    cout<<mx_sum<<'\n';
}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}