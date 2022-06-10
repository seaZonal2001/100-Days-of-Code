#include<bits/stdc++.h>
using namespace std;
int shortestCycle(int V,vector<int> graph[]){

    int ans=1e9;

    //running BFS starting from each vertex
    for(int i=0;i<V;i++){
        vector<int> dist(V,1e9),parent(V,-1);
        queue<int> q;

        q.push(i);
        dist[i]=0;
        
        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(auto &v:graph[u]){
                if(dist[v]==1e9){
                    parent[v]=u;
                    dist[v]=1+dist[u];
                    q.push(v);
                }else if(v!=parent[u]){
                    ans=min(ans,dist[u]+dist[v]+1);
                }
            }
        }
    }
    if(ans==1e9)return -1; //no cycle
    return ans;
}