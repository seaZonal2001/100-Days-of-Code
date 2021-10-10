#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<vector<int>> s, l, r, u, d;
set<array<int,2>> eliminate;
bool check(int i,int j){
    int nc=0,sc=0;
    if(l[i][j]!=-1)nc++,sc+=s[i][l[i][j]];
    if(r[i][j]!=-1)nc++,sc+=s[i][r[i][j]];
    if(u[i][j]!=-1)nc++,sc+=s[u[i][j]][j];
    if(d[i][j]!=-1)nc++,sc+=s[d[i][j]][j];

    return s[i][j]*nc<sc;
}
void checkUtil(int i,int j){
    if(check(i,j))eliminate.insert({i,j});
    else eliminate.erase({i,j});
}
int solution(){
    cin>>n>>m;
    s=vector<vector<int>>(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        cin>>s[i][j];
    }
    l=r=u=d=vector<vector<int>>(n,vector<int>(m));

    //linking neighbouring cells
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            l[i][j]=j-1;
            r[i][j]=j<m-1?j+1:-1;
            u[i][j]=i-1;
            d[i][j]=i<n-1?i+1:-1;
        }
    }

    int sa=0;

    //sum of alive
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        sa+=s[i][j];
    }

    //to be eliminated
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            checkUtil(i,j);
        }
    }

    //stimulate
    int ans=0;
    for(bool f=1;f;){
        f=0;
        ans+=sa;
        set<array<int,2>> eliminate2=eliminate;
        eliminate={};
        for(auto a:eliminate2){
            f=1;
            int i=a[0],j=a[1];
            sa-=s[i][j];
            if(l[i][j]!=-1){
                r[i][l[i][j]]=r[i][j];
                checkUtil(i,l[i][j]);
            }
            if(r[i][j]!=-1){
                l[i][r[i][j]]=l[i][j];
                checkUtil(i,r[i][j]);
            }
            if(u[i][j]!=-1){
                d[u[i][j]][j]=d[i][j];
                checkUtil(u[i][j],j);
            }
            if(d[i][j]!=-1){
                u[d[i][j]][j]=u[i][j];
                checkUtil(d[i][j],j);
            }
            eliminate.erase({i,j});
        }

    }
    return ans;

}
int32_t main(){
    int testCase;
    cin>>testCase;
    for(int i=1;i<=testCase;i++){
        cout<<"Case #"<<i<<": "<<solution()<<'\n';
    }
}