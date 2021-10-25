#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n;cin>>n;
    vector<int> ratings(n+2);
    for(int i=1;i<=n;i++)cin>>ratings[i];
    ratings[0]=ratings[n+1]=1e9;
    vector<pair<int,int>> v;
    for(int i=1;i<=n;i++){
        v.push_back({ratings[i],i});
    }
    sort(v.begin(),v.end());
    vector<int> minutes(n+2,0);
    int id;
    int time;
    long long ans=0;
    for(auto i:v){
        id=i.second;
        time=1;
        if(ratings[id]>ratings[id-1]){
            time=max(time,minutes[id-1]+1);
        }
        if(ratings[id]>ratings[id+1]){
            time=max(time,minutes[id+1]+1);
        }

        minutes[id]=time;
        ans+=time;

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