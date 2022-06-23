#include <iostream>
#include <vector>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    for(auto &x:arr)cin>>x;
    int l=0,r=n-1;
    while(l<r)swap(arr[l++],arr[r--]);
    for(auto &x:arr)cout<<x<<' ';
    cout<<'\n';
}
int main() {
	int t;cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}