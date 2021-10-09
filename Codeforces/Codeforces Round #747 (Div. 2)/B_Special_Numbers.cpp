//Better Than Yesterday
#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
int exp_pow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
void binary(int n){
    string res;
    while(n){
        if(n&1)res+='1';
        else res+='0';
        n>>=1;
    }
    reverse(res.begin(),res.end());
    cout<<res<<'\n';
}
void solve(){
 ll n,k;cin>>n>>k;
 ll ans=0;
//  binary(k);
 for(ll i=0;i<32;i++){
     if((k&(1LL<<i))>0){
         ans=(ans+exp_pow(n,i))%mod;
     }
 }
 cout<<ans<<'\n';
}

int main()
{
fast
int t;
cin>>t;
while(t--){
solve();
}
return 0;
}