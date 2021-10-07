#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n;cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)cin>>i;
    stack<int> st;
    vector<int> left(n),right(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i])st.pop();
        if(st.empty())left[i]=0;
        else left[i]=st.top()+1;
        st.push(i);
    }
    while(!st.empty())st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
        if(st.empty())right[i]=n;
        else right[i]=st.top();
        st.push(i);
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=arr[i]*(right[i]-i)*(i-left[i]+1);
    }
    cout<<ans<<'\n';

}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}