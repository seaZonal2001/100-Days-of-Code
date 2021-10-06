#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n,k;
    cin>>n>>k;
    map<int,int> hash;
    int x;
    for(int i=0;i<n;i++)
    cin>>x,hash[x]++;

    long long ans=1LL*n*(n-1)/2;  //total pairs if all numbers are considered distinct.

    priority_queue<pair<int,int>> pq;

    for(auto i:hash)
    if(i.second>1){
        pq.emplace(i.second,i.first);
        ans-=1LL*i.second*(i.second-1)/2; //these pairs had both element equal so subtract from total
        }

    for(int i=0;i<k;i++){
        if(pq.empty())break;
        auto it=pq.top();           //top element of priority queue ensure that if one element is change it will result in formation of max pairs.
        ans+=it.first-1;
        it.first--;
        if(it.first>1)pq.push(it);
    }
    cout<<ans<<'\n';


}

    
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
    return 0;
}