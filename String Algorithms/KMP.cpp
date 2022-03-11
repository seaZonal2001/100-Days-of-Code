#include<bits/stdc++.h>
using namespace std;

// TC and SC : O(N)
vector<int> KMP(string s){
    int n=s.length();
    vector<int> lps(n,0);
    int i=1,len=0;
    while(i<n){
        if(s[i]==s[len]){
            lps[i++]=++len;
        }else{
            if(len>0){
                len=lps[len-1];
            }else{
                lps[i++]=len;
            }
        }
    }
    return lps;
}
int main(){
    string pat,txt;cin>>pat>>txt;
    vector<int> lps=KMP(pat+'#'+txt);
    //now from the lps array you can find count and position of pat in txt if present.
    
    //string s;cin>>s; vector<int> lps=KMP(s);  //you can find longest prefix suffix using this ,string compression problem can be solved as well
    return 0;
}