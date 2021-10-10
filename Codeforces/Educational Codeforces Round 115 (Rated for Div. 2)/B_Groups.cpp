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
void solve(){
 int n;cin>>n;
 vector<vector<int>> v(n,vector<int>(5));
 for(int i=0;i<n;i++){
     for(int j=0;j<5;j++)
     cin>>v[i][j];
 }
 for(int i=0;i<5;i++){
     
     for(int j=i+1;j<5;j++){
         set<int> s;
         int a=0,b=0;
         for(int k=0;k<n;k++){
             if(v[k][i]){
                 a++;
                 s.insert(k);
             }
             if(v[k][j]){
                 b++;
                 s.insert(k);
             }
         }
         if(s.size()==n){
             int common=a+b-(int)s.size();
             a-=common,b-=common;
            if(a<=n/2 && b<=n/2){
                cout<<"YES\n";
                return;
            }
         }
     }
 }
 cout<<"NO\n";
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