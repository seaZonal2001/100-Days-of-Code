#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n,m;
    cin>>n>>m;
    unordered_set<int> A;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        A.insert(x);
    }

    for(int i=0;i<m;i++){
        cin>>x;
        if(A.find(x)!=A.end()){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
            A.insert(x);
        }
    }
}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}