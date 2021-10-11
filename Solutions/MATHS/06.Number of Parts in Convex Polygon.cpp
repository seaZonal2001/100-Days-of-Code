#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
int getDiagonals(int n){
    return 1LL*n*(n-3)/2%MOD;
}
int getIntersectingDiagonals(int n){
    if(n<4)return 0;
    return 1LL*n*(n-1)%MOD*(n-2)%MOD*(n-3)%MOD/24;
}
void solution(){
    int n;cin>>n;
    cout<<((1+getDiagonals(n))%MOD+getIntersectingDiagonals(n))%MOD<<'\n';
}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}