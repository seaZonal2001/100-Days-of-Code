#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    map<int,int> cnt;
    string s;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>s;
        int mask=0;
        for(char c:s){
            mask^=(1LL<<(c-'a'));
        }
        ans+=cnt[mask];

        for(int j=0;j<26;j++){
            mask^=(1LL<<j);
            ans+=cnt[mask];
            mask^=(1LL<<j);
        }
        cnt[mask]++;
    }
    cout<<ans;
}