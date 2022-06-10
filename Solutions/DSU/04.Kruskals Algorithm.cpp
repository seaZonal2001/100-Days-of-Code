#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int u,v,w;
};

class DSU{
    int *parent,*rank;
    public:
    DSU(int V){
        parent=new int[V+1];
        rank=new int[V+1];
        for(int i=0;i<=V;i++)parent[i]=i,rank[i]=1;
    }
    int find(int x){
        return x==parent[x]?x:(parent[x]=find(parent[x]));
    }
    void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(rank[x]<rank[y])swap(x,y);
        parent[y]=x;
        if(rank[x]==rank[y])rank[x]++;
    }
};

int main(){
    int V,E;cin>>V>>E;
    vector<Edge> edges(E);
    
    for(int i=0;i<E;i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    }
    sort(edges.begin(),edges.end(),[](Edge &a,Edge &b){
        return a.w<b.w;
    });

    DSU g(V);
    int res=0;
    for(int i=0;i<E;i++){
        int u=edges[i].u,v=edges[i].v,w=edges[i].w;
        if(g.find(u)!=g.find(v)){
            g.unite(u,v);
            res+=w;
        }
    }
    cout<<res;
}