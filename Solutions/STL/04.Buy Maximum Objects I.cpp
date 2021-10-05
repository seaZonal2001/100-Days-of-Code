#include<bits/stdc++.h>
using namespace std;

//O(NlogN) time and O(1) space;
void solution(){
    int n,m;
    cin>>n>>m;
    vector<int> price(n);
    for(auto &i:price)
    cin>>i;

    sort(price.begin(),price.end());
    int res=0;
    for(int i=0;i<n;i++){
        if(price[i]<=m){
            res++;
            m-=price[i];
        }
    }
    cout<<res<<'\n';
}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}