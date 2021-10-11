#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
void solution(){
    int n;cin>>n;
    if(n<4){
        cout<<"0\n";
        return;
    }
    cout<<1LL*n*(n-1)%MOD*(n-2)%MOD*(n-3)%MOD/24<<'\n';
}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}