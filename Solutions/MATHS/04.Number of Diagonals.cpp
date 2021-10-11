#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
void solution(){
    int n;cin>>n;
    cout<<1LL*n*(n-3)/2%MOD<<'\n';
}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}