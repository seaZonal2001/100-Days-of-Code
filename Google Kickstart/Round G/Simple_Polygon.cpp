#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,a;cin>>n>>a;
    // if(n==3){
    //     cout<<"POSSIBLE\n";
    //     cout<<"0 0\n0 1\n"<<a<<" "<<0<<'\n';
    // }else if(n==4){
    //     cout<<"POSSIBLE\n";
    //     cout<<0<<" "<<0<<'\n';
    //     cout<<0<<" "<<1<<'\n';
    //     cout<<a/2<<" "<<1<<'\n';
    //     cout<<a/2<<" "<<0<<'\n';

    // }else if(n==5){
    //     if(a%3){
    //         cout<<"IMPOSSIBLE\n";   
    //         return;
    //     }else{
    //         cout<<"POSSIBLE\n";
    //         cout<< 0<<" "<< 0<<'\n';
    //         cout<< a/3<<" "<< 0<<'\n';
    //         cout<< a/3<<" "<< 1<<'\n';
    //         cout<< a/6<<" "<< 2<<'\n';
    //         cout<< 0<<" "<< 1<<'\n';
    //     }
    // }
}
int main(){
    int tt;cin>>tt;
    for(int i=1;i<=tt;i++){
        cout<<"Case #"<<i<<": ";
        solve();
       
    }
}