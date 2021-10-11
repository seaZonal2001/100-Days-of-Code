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
void solve(){
 int n;cin>>n;
 vector<vector<int>> arr(n,vector<int>(2));

 map<int,int> topic,difficulty;
 for(int i=0;i<n;i++){
     cin>>arr[i][0]>>arr[i][1];
     topic[arr[i][0]]++;
     difficulty[arr[i][1]]++;
 }
 int ans=1LL*n*(n-1)*(n-2)/6;
 for(int i=0;i<n;i++){
     ans-=1LL*(topic[arr[i][0]]-1)*(difficulty[arr[i][1]]-1);
 }
 cout<<ans<<'\n';
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