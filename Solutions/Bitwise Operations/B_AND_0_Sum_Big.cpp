#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
int exp_pow(int a,int b){
    int res=1;
    while(b){
        if(b&1)res=1LL*res*a%MOD;
        a=1LL*a*a%MOD;
        b>>=1;
    }
    return res;
}
void solution(){
    int n,k;cin>>n>>k;
    cout<<exp_pow(n,k)<<'\n';
}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}