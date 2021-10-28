#include<bits/stdc++.h>
using namespace std;
#define int long long
void solution(){
    int n;cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)cin>>i;

    vector<int>  mask(31,0);
    for(int i=30;i>0;i--){
        for(int j=0;j<n;j++)
        if(((1<<i)-1)&arr[j]==arr[j] && arr[j]&(1<<(i-1)))
        mask[i]++,arr[j]=0;
    }
    int ans=0;
    for(int i=1;i<31;i++){
        if(mask[i])ans+=1LL*mask[i]*(mask[i]-1)/2;
    }
    cout<<ans<<'\n';
    
}
int32_t main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}