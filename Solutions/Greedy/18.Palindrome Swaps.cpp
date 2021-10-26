#include<bits/stdc++.h>
using namespace std;
void solution(){
    string s;cin>>s;
    vector<int> a(26,0);
    for(auto &i:s)a[i-'a']++;
    int l=0,r=s.length()-1;
    int swaps=0,i=0;
    bool ok=1;
    while(l<r){
        pair<int,int> cost(1e9,-1);
        
        for(int character=0;character<26;character++){
            if(a[character]<2)continue;
            int lCost=0,rCost=0;
            for(i=l;;i++){
                if((s[i]-'a')==character)break;
                lCost++;
            }
            for(i=r;;i--){
                if((s[i]-'a')==character)break;
                rCost++;
            }
            cost=min(cost,{lCost+rCost,character});
        }
        if(cost.second==-1){
            ok=0;
            break;
        }
        swaps+=cost.first;
        a[cost.second]-=2;

        for(i=l;;i++){
            if((s[i]-'a')==cost.second)break;
        }
        while(i>l){
            swap(s[i],s[i-1]);
            i--;
        }
        for(i=r;;i--){
            if((s[i]-'a')==cost.second)break;
        }
        while(i<r){
            swap(s[i],s[i+1]);
            i++;
        }
        l++,r--;
    }
    if(!ok)cout<<"Impossible\n";
    else cout<<swaps<<'\n';
}
int main(){
    int testCase;
   // cin>>testCase;
   testCase=1;
    while(testCase--){
        solution();
    }
}