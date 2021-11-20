#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;cin>>n>>k;
    int h[n];
    for(int i=0;i<n;i++)cin>>h[i];
    vector<int> dp(n+1,0);
    
    for(int i=2;i<=n;i++){
      dp[i]=INT_MAX;
        for(int j=1;j<=k;j++){
            if(j<i){
                dp[i]=min(dp[i],dp[i-j]+abs(h[i-1]-h[i-j-1]));
            }
        }
    }
    cout<<dp[n];
}