#include<bits/stdc++.h>
using namespace std;
#define int long long
int smallestSubArrayWithGivenSum(int arr[],int reqSum,int n)
{
 
    // There would be no sub-array as an answer
    // if the array in the question is empty.
    
    if (n == 0) {
        return INT_MAX;
    }
 
    // Initializing variables.
    int len = INT_MAX, left = 0, right = 0, startIndex = -1,
        currSum = arr[0];
 
    // Traversing the array.
    while (right < n) {
 
        // When both the index-holders have
        // the same value.
        if (left == right) {
 
            // Modifying length and startingIndex
            // both both 'left' and 'right' are
            // same and have the value of the
            // required sum.
            if (currSum == reqSum) {
                len = min(1LL, len);
                startIndex = left;
            }
 
            // Incrementing 'right; and adding the
            // value at that index to the current
            // sum.
            right++;
            currSum += arr[right];
            continue;
        }
 
        // Dropping the element at index 'left'
        // from the current sum if current sum
        // becomes greater than the required value.
        if (currSum > reqSum) {
            currSum -= arr[left];
            left++;
        }
 
        else {
 
            // Modifying length and starting index
            // if current sum is equal to the required
            // sum.
            if (reqSum == currSum
                && right - left + 1 < len) {
                len = min(len, right - left + 1);
                startIndex = left;
            }
 
            // Incrementing 'right; and adding the
            // value at that index to the current
            // sum.
            right++;
            currSum += arr[right];
        }
    }
 
    // If the length of the answer sub-array results over
    // the length of the initial array, it means that the
    // answer does not exist.
    if (len > n) {
        return INT_MAX;
    }
 
    return len;
}
void solve(){
    int n,K;cin>>n>>K;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int sum=0,tsum,ans=LLONG_MAX;
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==K){
                ans=min(ans,j-i+1);
                break;
            }
               int aux=smallestSubArrayWithGivenSum(arr+j+1,K-sum,n-j-1);
                if(aux!=INT_MAX){
                {ans=min(ans,j-i+1+aux);}
            }
            
        }
       // cout<<ans<<" ";
    }
    if(ans==LLONG_MAX)cout<<-1;
    else cout<<ans;
}
int32_t main(){
    int tt;cin>>tt;
    for(int i=1;i<=tt;i++){
        cout<<"Case #"<<i<<": ";
        solve();
        cout<<'\n';
    }
}