#include<bits/stdc++.h>
using namespace std;
void solution(){
    int n;cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)cin>>i;

    vector<int> left(n),right(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
        left[i]=(st.empty())?-1:st.top();
        st.push(i);
    }
    while(!st.empty())st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
        right[i]=(st.empty())?n:st.top();
        st.push(i);
    }
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int x=right[i]-left[i]-2; //because of zero based indexing
        ans[x]=max(ans[x],arr[i]);
    }

    for(int i=n-2;i>=0;i--){
        ans[i]=max(ans[i],ans[i+1]);
    }
    for(const auto &i:ans)
    cout<<i<<" ";
    cout<<'\n';

}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}