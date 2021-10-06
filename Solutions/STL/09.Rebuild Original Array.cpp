#include<bits/stdc++.h>
using namespace std;
#define int long long
void solution(){
    int n;
    cin>>n;
    n=(1LL<<n);
    vector<int> arr(n);
    for(auto &i:arr)cin>>i;
    sort(arr.begin(),arr.end());

    map<int,int> subSum;
    vector<int> ans;
    vector<int> utillSum;
    subSum[0]=1;

    for(int i=1;i<n;i++){
        if(subSum[arr[i]]){
            subSum[arr[i]]--;
        }else{
            ans.push_back(arr[i]);
            vector<int> temp;
            for(auto &j:utillSum)
            temp.push_back(j+arr[i]),subSum[j+arr[i]]++;

            for(auto &j:temp)
            utillSum.push_back(j);
            utillSum.push_back(arr[i]);
        }
    }
    for(const auto &i:ans)cout<<i<<" ";
    cout<<'\n';
}
int32_t main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}