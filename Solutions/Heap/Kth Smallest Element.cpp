#include<bits/stdc++.h>
using namespace std;

// Time : O(NlogK)
void solution(){
    int n;cin>>n;
    vector<int> arr(n);
    for(auto i:arr)cin>>i;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k)pq.pop();
    }
    cout<<pq.top()<<'\n';
}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}