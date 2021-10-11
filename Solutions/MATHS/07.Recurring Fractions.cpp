#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string fractionToDecimal(long numerator,long denominator){
         string ans;
        if(numerator==0)return "0";

        ans=(numerator<0)^(denominator<0)?"-":"";
        numerator=abs(numerator);
        denominator=abs(denominator);
        ans+=to_string(numerator/denominator);
        numerator%=denominator;
        if(numerator==0)return ans;
        ans+=".";
        map<long ,int> hash;
        hash[numerator]=ans.length();
        while(numerator){
            numerator*=10;
            ans+=to_string(numerator/denominator);
            numerator%=denominator;
            if(hash.find(numerator)!=hash.end()){
                int index=hash[numerator];
                ans=ans.substr(0,index)+"("+ans.substr(index)+")";
                break;
            }
            hash[numerator]=(int)ans.length();
        }
        return ans;
    }
};
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        int numerator,denominator;
        cin>>numerator>>denominator;
        Solution obj;
        string ans=obj.fractionToDecimal(numerator,denominator);
        cout<<ans<<'\n';
    }
}