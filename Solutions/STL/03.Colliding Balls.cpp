//O(NlogN) time and O(N) space
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,m;
    cin>>n>>m;
    multiset<int> s;
    int p,v;
    for(int i=0;i<n;i++){
        cin>>p>>v;
        s.insert(p*v);
    }

    int res=0;
    for(int i=0;i<m;i++){
        cin>>p>>v;
        auto it=s.find(p*v);
        if(it!=s.end()){
            res++;
            s.erase(it);
        }
    }
    cout<<res;
}