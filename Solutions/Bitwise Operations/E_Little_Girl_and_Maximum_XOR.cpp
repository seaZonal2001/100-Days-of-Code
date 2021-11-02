#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll l,r;cin>>l>>r;
    ll e=l^r;
    if(e==0){
        cout<<"0\n";
    }else{
        ll msb=63-__builtin_clzll(e);
        cout<<2*(1LL<<msb)-1;
    }
}