#include<bits/stdc++.h>
using namespace std;
void solution(){
   int n;cin>>n;
   int x;
   int freq[1000001]={0};
   for(int i=0;i<n;i++){
       cin>>x;
       freq[x]++;
   }
   int mx_freq=*max_element(freq,freq+1000001);
   if(mx_freq>=(n+1)/2){
       int common=mx_freq-(n-mx_freq);
       cout<<n-common<<'\n';
   }else{
       cout<<n<<'\n';
   }
}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        solution();
    }
}