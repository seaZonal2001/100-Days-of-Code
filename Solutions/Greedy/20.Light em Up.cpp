#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    bool zero=0;
    for(auto &i:arr)cin>>i,zero|=(i==0);
    if(k==0){
        if(zero)cout<<"-1\n";
        else cout<<"0\n";
        return ;
    }
    vector<bool> flip(n+1,0);
    bool ok=1,invert=0;
    int ans=0;
    for(int i=0;i<n;i++){
        invert^=flip[i];
        if((arr[i]^invert)==0){
            if(i+k-1<n){
                ans++;
                invert^=1;
                flip[i+k]=flip[i+k]^1;
            }else{
                ok=0;
                break;
            }
        }
    }
    if(!ok)ans=-1;
    cout<<ans<<'\n';
}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}