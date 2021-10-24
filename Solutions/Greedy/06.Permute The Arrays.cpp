#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(b[i]-a[i]);
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