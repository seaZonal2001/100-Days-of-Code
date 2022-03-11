#include<bits/stdc++.h>
using namespace std;

//TC and SC : O(N)
vector<int> manachers(string s){
    int n=s.length();
    vector<int> LPS(n,0);
    int c=0,r=0;
    for(int i=1;i<n-1;i++){
        int mirror = c-(i-c);
        if(i<r){
            LPS[i]=min(LPS[mirror],r-i);
        }
        while(s[i+i+LPS[i]]==s[i-1-LPS[i]])LPS[i]++;
        if(i+LPS[i]>r){
            c=i;
            r=i+LPS[i];
        }
    }
    return LPS;
}
int main(){
    string s;cin>>s;
    string t;
    t+='@';
    for(auto &c:s)t+='#'+c;
    t+="#&";
    vector<int> LPS=manachers(t); // you can find longest palindromic substring
}