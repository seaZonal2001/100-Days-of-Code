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
int check1(string &s){
    int n=s.length();
    int z=-1,t=-1;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='0'){
            z=i;
            break;
        }
    }
    if(z==-1)return n;
    for(int i=z-1;i>=0;i--){
        if(s[i]=='0' || s[i]=='5'){
            t=i;
            break;
        }
    }
    if(t==-1)return n;
    return n-z-1+z-t-1;
}
int check2(string &s){
    int n=s.length();
    int z=-1,t=-1;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='5'){
            z=i;
            break;
        }
    }
    if(z==-1)return n;
    for(int i=z-1;i>=0;i--){
        if(s[i]=='2' || s[i]=='7'){
            t=i;
            break;
        }
    }
    if(t==-1)return n;
    return n-z-1+z-t-1;
}
void solve(){
 string s;cin>>s;
 int n=s.length();
// cout<<check1(s)<<" "<<check2(s)<<'\n';
 int ans=min(check1(s),check2(s));
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