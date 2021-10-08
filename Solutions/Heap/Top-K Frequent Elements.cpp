#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n,k;cin>>n>>k;
    unordered_map<int,int> hash;
    int x;
    for(int i=0;i<n;i++)cin>>x,hash[x]++;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(auto i:hash){
        pq.emplace(i.second,i.first);
        if(pq.size()>k)pq.pop();
    }
    while(!pq.empty())cout<<pq.top().second<<" ",pq.pop();
    cout<<'\n';
}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}