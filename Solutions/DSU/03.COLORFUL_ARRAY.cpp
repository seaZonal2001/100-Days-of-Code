#include<bits/stdc++.h>
using namespace std;
class DSU{
    vector<int> parent;
    public:
    DSU(int n){
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
    }
    int find(int x){
        return x==parent[x]?x:(parent[x]=find(parent[x]));
    }
    void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x!=y){
            parent[x]=max(parent[x],parent[y]);
            parent[y]=max(parent[x],parent[y]);
        }
    }
};
int main(){
    int n,q;cin>>n>>q;
    int l[q],r[q],c[q];
    for(int i=0;i<q;i++)cin>>l[i]>>r[i]>>c[i];

    DSU g(n+2);
    int res[n+2]={0};
    for(int i=q-1;i>=0;i--){
        int id=g.find(l[i]);
        while(id<=r[i]){
            res[id]=c[i];
            g.unite(id,id+1);
            id=g.find(id);
        }
    }
    for(int i=1;i<=n;i++)cout<<res[i]<<'\n';
    return 0;
}