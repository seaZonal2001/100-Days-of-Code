#include<bits/stdc++.h>
using namespace std;
#define int long long 
map<pair<int,int>,int> dp;
long long getProfit(vector<int>& wt,vector<int>& val,int n,int w){
    if(n==0 || w==0)return 0;
    if(dp.find({n,w})!=dp.end())return dp[{n,w}];
    if(wt[n-1]<=w)
        return dp[{n,w}]=max(val[n-1]+getProfit(wt,val,n-1,w-wt[n-1]),getProfit(wt,val,n-1,w));
    else
        return dp[{n,w}]=getProfit(wt,val,n-1,w);
}
int32_t main(){
    int n,w;cin>>n>>w;
    vector<int> wt(n),val(n);
    for(int i=0;i<n;i++)cin>>wt[i]>>val[i];
    cout<<getProfit(wt,val,n,w);
}