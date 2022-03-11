#include<bits/stdc++.h>
using namespace std;

//TC and SC : O(N)
vector<int> Zalgo(string s){
    int n=s.length();
    int l=0,r=0;
    vector<int> Z(n,0);

    for(int i=1;i<n;i++){
        if(i<=r)Z[i]=min(r-i+1,Z[i-l]);
        while(i+Z[i]<n && s[Z[i]]==s[i+Z[i]])Z[i]++;
        if(i+Z[i]-1>r){
            l=i;
            r=i+Z[i]-1;
        }
    }
    return Z;
}
int main(){
    string pat,txt;cin>>pat>>txt;
    vector<int> Z=Zalgo(pat+'#'+txt); //ith index represent length of longest substring starting at index i which is also a proper prefix
}