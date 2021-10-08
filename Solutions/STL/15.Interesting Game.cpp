#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n;cin>>n;
    vector<pair<int,int>> v(n);
    for(auto &i:v)cin>>i.first;
    for(auto &i:v)cin>>i.second;
    sort(v.begin(),v.end(),[](pair<int,int>&a,pair<int,int>&b){
        return a.first+a.second>b.first+b.second;
    });
    int a=0,b=0;
    for(int i=0;i<n;i++){
        if(!(i&1))
        a+=v[i].first;
        else
        b+=v[i].second;
    }
    if(a>b)cout<<"Alice\n";
    else if(a<b) cout<<"Bob\n";
    else cout<<"Tie\n";

}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}