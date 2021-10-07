#include <bits/stdc++.h>
using namespace std;
void solution(){
    int n,k;cin>>n>>k;
    priority_queue<int,vector<int>,greater<int>> pq;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        pq.push(x);
        if(pq.size()>k)
        cout<<pq.top()<<" ",pq.pop();
    }
    while(!pq.empty())cout<<pq.top()<<" ",pq.pop();
    cout<<'\n';
}
int main() {
	int testCase;
	cin>>testCase;
	while(testCase--){
	    solution();
	}
	return 0;
}