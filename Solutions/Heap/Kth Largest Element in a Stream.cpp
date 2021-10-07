#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n,x;cin>>n;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        cin>>x;
        pq.push(x);
        if(pq.size()>k)pq.pop();
        cout<<pq.top()<<" ";
    }
    cout<<'\n';
}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}