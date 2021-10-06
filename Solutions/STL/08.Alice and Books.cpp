#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n,x;
    cin>>n;
    multiset<int> s;
    for(int i=0;i<n;i++){
        cin>>x;
        s.insert(x);
        while(!s.empty() && *s.begin()<s.size())s.erase(s.begin());
        cout<<s.size()<<' ';
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