#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n;cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)cin>>i;

    int ans=arr[0];
    for(int i=1;i<n;i++)ans&=arr[i];
    cout<<ans<<'\n';
}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}