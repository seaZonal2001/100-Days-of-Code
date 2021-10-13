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
 vector<int> arr(k);
 for(auto &i:arr)cin>>i;
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
 for(int i=0;i<k;i++){
     pq.emplace(n-arr[i],i);
 }
 int ans=0;
 long long pd=0;
 while(!pq.empty()){
     while(!pq.empty() && pd>=(n-pq.top().first)){
         //cout<<"Popped :"<<pq.top().second<<'\n';
        pq.pop();
        }
     
     
     if(!pq.empty())
     pd+=pq.top().first,pq.pop(),ans++;
     
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