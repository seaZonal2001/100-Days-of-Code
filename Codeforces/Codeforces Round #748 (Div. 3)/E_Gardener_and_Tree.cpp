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
 int n,k;cin>>n>>k;
 if(n==1){
     cout<<0<<'\n';
     return;
 }
 vector<int> adj[n];
 int u,v;
 for(int i=1;i<n;i++){
     cin>>u>>v;
     --u,--v;
     adj[u].push_back(v);
     adj[v].push_back(u);
 }
 vector<int> degree(n,0);
 for(int i=0;i<n;i++){
     degree[i]=(int)adj[i].size();
 }
  vector<bool> visited(n,false);
 queue<int> q;
 for(int i=0;i<n;i++){
     if(degree[i]==1)q.push(i),visited[i]=true;
 }
 int cnt=0;

 while(!q.empty() && k--){
     int sz=q.size();
     for(int i=0;i<sz;i++){
         int u=q.front();
         q.pop();
         cnt++;
         for(auto v:adj[u]){
             if(!visited[v]){
                 degree[v]--;
                 if(degree[v]==1){
                     q.push(v);
                     visited[v]=true;
                 }
             }
         }

     }
 }
 cout<<n-cnt<<'\n';
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