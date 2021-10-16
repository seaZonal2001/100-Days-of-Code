#include<bits/stdc++.h>
using namespace std;
#define int long long
const int C=1000000000;
int getDist(vector<vector<int>>& v,int x,int y){
    int res=0,temp=INT_MAX;
    int n=v.size();
    for(int i=0;i<n;i++){
        temp=INT_MAX;
        if(x>=v[i][0] && x<=v[i][2] && y>=v[i][1] && y<=v[i][3]){
            temp=0;
        }else if(x>=v[i][0] && x<=v[i][2]){
            temp=min({temp,abs(y-v[i][1]),abs(y-v[i][3])});
        }else if(y>=v[i][1] && y<=v[i][3]){
            temp=min({temp,abs(x-v[i][0]),abs(x-v[i][2])});
        }else{
            temp=min({temp,abs(x-v[i][0])+abs(y-v[i][1]),abs(x-v[i][0])+abs(y-v[i][3])});
            temp=min({temp,abs(x-v[i][2])+abs(y-v[i][1]),abs(x-v[i][2])+abs(y-v[i][3])});
        }
        res+=temp;
    }
    return res;
}
void solve(){
    int k;cin>>k;
    vector<int> x(2*k),y(2*k);
    int j=0;
    for(int i=0;i<k;i++){
      cin>>x[j]>>y[j]>>x[j+1]>>y[j+1];
      j+=2;
    }
    //for(auto &i:x)cout<<i<<" ";cout<<'\n';
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
   cout<<x[k-1]<<" "<<y[k-1];
}
int32_t main(){
    int tt;cin>>tt;
    for(int i=1;i<=tt;i++){
        cout<<"Case #"<<i<<": ";
        solve();
        cout<<'\n';
    }
}