#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n;cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)cin>>i;
    long long ans=0;
    for(int i=1;i<n;i++){
        if(arr[i-1]>arr[i]){
            ans+=(arr[i-1]-arr[i]);
        }
    }
    cout<<ans<<'\n';

}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}