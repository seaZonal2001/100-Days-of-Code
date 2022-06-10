#include<bits/stdc++.h>
using namespace std;
const int MAX=1e9;
void solve(){
    int n,m;cin>>n>>m;
    int u,v;
    vector<pair<int,int>> graph[n+1];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        if(u==v)continue;
        graph[u].push_back({v,0});
        graph[v].push_back({u,1});
    }
    vector<int> dist(n+1,MAX);
    
    deque<int> q;
    q.push_back(1);
    dist[1]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop_front();
        for(auto &x:graph[u]){
            int v=x.first,w=x.second;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                if(w==0)q.push_front(v);
                else q.push_back(v);
            }
        }
    }
    cout<<(dist[n]==MAX?-1:dist[n]);
}
int main(){
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}