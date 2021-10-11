//Better Than Yesterday
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define PI (3.141592653589)
#define seal(x,y) ((x+y-1)/y)
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define all(x) x.begin(),x.end()
#define float long double
int digit_sum(int n){
int sum=0;
while(n)
sum+=(n%10),n/=10;
return sum;
}

//int digicnt_fact(int n)
//{
//if(n<0) return 0;  //factorial doesn't exist
//if(n<=1) return 1; //base case
//double x=((n * log10(n / M_E) +log10(2 * M_PI * n) /2.0));  //Kamenetsky's formula
//return floor(x)+1;
//}
int getPairsCount(vector<int> &arr, int n, float sum)
{
    map<float, int> m;
 
 
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
 
    int twice_count = 0;
 
    
    for (int i = 0; i < n; i++) {
        twice_count += m[sum - arr[i]];
 
        if (sum - arr[i] == arr[i])
            twice_count--;
    }
 
   
    return twice_count / 2;
}
void solve(){
 int n;cin>>n;
 vector<int> arr(n);
 float avg=0;
 for(auto &i:arr)cin>>i,avg+=i;
 avg/=n;
 float target=2*avg;
//  cout<<target;
 cout<<getPairsCount(arr,n,target)<<'\n';
}

int32_t main()
{
fast
int t;
cin>>t;
while(t--){
solve();
}
return 0;
}