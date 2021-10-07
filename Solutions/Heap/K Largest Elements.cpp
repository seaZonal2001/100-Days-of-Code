#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n;
    cin>>n;
    int x;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        cin>>x;
        pq.push(x);
        if(pq.size()>k)pq.pop();
    }
    while(!pq.empty())cout<<pq.top()<<" ",pq.pop();
}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}