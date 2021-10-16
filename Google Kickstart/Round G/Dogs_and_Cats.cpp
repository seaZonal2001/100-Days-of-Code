#include<bits/stdc++.h>
using namespace std;
#define int long long
string solve(){
    int n,d,c,m;
    cin>>n>>d>>c>>m;
    string s;cin>>s;
    int cntD=0;
    for(auto &i:s)if(i=='D')cntD++;
    
    for(auto &i:s){
        if(i=='C'){
            if(c==0)break;
            else c--;
        }else{
            if(d==0)break;
            else d--,c+=m;
            cntD--;
        }
    }
    if(cntD==0)return "YES";
    else return "NO";
}
int32_t main(){
    int tt;cin>>tt;
    for(int i=1;i<=tt;i++){
        cout<<"Case #"<<i<<": "<<solve()<<'\n';
    }
}