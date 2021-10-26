#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n,k;cin>>n>>k;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>v[i].second;
    }
    sort(v.begin(),v.end(),[](pair<int,int>&a,pair<int,int>&b){
        return a.second*b.first<=a.first*b.second;
    });

    priority_queue<int> pq;
    int t_sum=0;
    for(int i=0;i<k;i++){
        t_sum+=v[i].first;
        pq.push(v[i].second);
    }
    double amount= (double)t_sum*v[k-1].second/v[k-1].first;
    for(int i=k;i<n;i++){
        pq.push(v[i].second);
        t_sum+=v[i].first;
        t_sum-=pq.top();
        pq.pop();
        amount=min(amount,(double)t_sum*v[i].second/v[i].first);
    }
    cout<<amount<<'\n';
}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}