#include<bits/stdc++.h>
using namespace std;
int moves[4][2]={{1,0},{-1,0},{0,-1},{1,0}};
void solution(){
    int n;cin>>n;
    string s;cin>>s;
    int x=0,y=0,dir=0;
    for(int i=0;i<n;i++){
        if(s[i]=='L')
        dir=(dir+1)%4;
        else if(s[i]=='R')
        dir=(dir-1+4)%4;
        else{
            x+=moves[dir][0];
            y+=moves[dir][1];
        }
    }
    if((x==0 && y==0) || dir!=0)cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    int testCase;cin>>testCase;
    while(testCase--){
        solution();
    }
}