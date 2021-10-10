#include<bits/stdc++.h>
using namespace std;
void solution(){
    int a,b,c;cin>>a>>b>>c;
    //Linear Diophantine Equation
    if(c%__gcd(a,b))cout<<"NO\n";
    else cout<<"YES\n";
}
int main(){
    int testCase;cin>>testCase;
    while(testCase--){
        solution();
    }
}