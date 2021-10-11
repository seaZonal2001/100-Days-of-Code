#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1000000007;
int fact[100001],factInv[100001];
int numInv[100001];
void inverse(){
    numInv[1]=1;
    for(int i=2;i<100001;i++){
        numInv[i]= (numInv[MOD%i]*(MOD-MOD/i))%MOD;
    }
}
void factorialInverse(){
    factInv[0]=factInv[1]=1;
    for(int i=2;i<100001;i++){
        factInv[i]=(numInv[i]*factInv[i-1])%MOD;
    }
}
void factorial(){
    fact[0]=1;
    for(int i=1;i<100001;i++){
        fact[i]=(i*fact[i-1])%MOD;
    }
}
int nCr(int n,int r){
    return (fact[n]*factInv[n-r]%MOD*factInv[r])%MOD;
}
void solution(){
    int n,m;cin>>n>>m;
    cout<<nCr(n+m,n)<<"\n";
}
int32_t main(){
    inverse();
    factorial();
    factorialInverse();
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}