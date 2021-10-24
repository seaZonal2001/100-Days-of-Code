#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n;cin>>n;
    vector<int> x(n),y(n);
    for(auto &i:x)cin>>i;
    for(auto &i:y)cin>>i;
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int id=(n-1)/2;
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(x[i]-x[id]);
        ans+=abs(y[i]-y[id]);
    }
    cout<<ans<<'\n';
}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}