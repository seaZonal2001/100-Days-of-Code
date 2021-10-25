#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n;cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());

    set<pair<int,int>> s;
    int ans=0;
    for(int i=n-1;i>=0;i--){
        s.insert({v[i].second,v[i].first});
        int time=v[i].first-(i?v[i-1].first:0);
        while(time && !s.empty()){
            auto it=s.begin();
            if(time>=it->first){
                time-=it->first;
                ans++;
            }else{
                s.insert(it->first-time,it->second);
                time=0;
            }
            s.erase(it);
        }
        
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