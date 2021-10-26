#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n;cin>>n;
    vector<int> arr(n);
    long long S=0;
    for(auto &i:arr){
        S+=i;
    }
    int X1=S/n,X2=(S+n-1)/n;
    long long S1=0,S2=0;
    for(int i=0;i<n;i++){
        S1+=1LL*(arr[i]-X1)*(arr[i]-X1);
        S2+=1LL*(arr[i]-X2)*(arr[i]-X2);
    }
    cout<<min(S1,S1)<<'\n';
}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}