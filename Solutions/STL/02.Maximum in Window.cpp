#include<bits/stdc++.h>
using namespace std;

//Approach 1 O(N) time and space

void solution1(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &i:arr)
    cin>>i;

    deque<int> dq;
    
    for(int i=0;i<k;i++){
        while(!dq.empty() && arr[dq.back()]<=arr[i])
        dq.pop_back();
    }

    cout<<arr[dq.front()]<<" ";
    for(int i=k;i<n;i++){
        while(!dq.empty() && dq.front()<=i-k)
        dq.pop_front();
        while(!dq.empty() && arr[dq.back()]<=arr[i])
        dq.pop_back();

        dq.push_back(i);
        cout<<arr[dq.front()]<<" ";
    }
}

//Approach 2 O(NlogN) time and O(N) space;

void solution2(){
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    for(auto &i:arr) cin>>i;
    multiset<int> s;
    for(int i=0;i<k;i++)s.insert(arr[i]);
    for(int i=0;i<=n-k;i++){
        cout<<*(s.rbegin())<<" ";
        s.erase(s.find(arr[i]));
        if(i+k<n)s.insert(arr[i]);
    }

}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
       solution1();
    }
}