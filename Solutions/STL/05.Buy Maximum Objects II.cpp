#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,q;
    cin>>n>>q;
    vector<int> price(n);
    for(auto &i:price)
    cin>>i;
    sort(price.begin(),price.end());
    for(int i=1;i<n;i++)
    price[i]+=price[i-1];

    int res=0,m;
    for(int i=0;i<q;i++){
        cin>>m;
        auto pos=lower_bound(price.begin(),price.end(),m)-price.begin();
        if(pos!=n && price[pos]==m){
            cout<<pos+1<<'\n';
        }else{
            cout<<pos<<'\n';
        }
    }
}