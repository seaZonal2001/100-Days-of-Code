#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n;cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)cin>>i;
    int g=arr[0];
    for(int i=1;i<n;i++)g=__gcd(g,arr[i]);
    if(g>1)cout<<"Yes\n";
    else cout<<"No\n";
}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}