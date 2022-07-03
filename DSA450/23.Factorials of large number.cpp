// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
    void mul(int a,int &len,vector<int> &res){
        int carry=0;
        for(int i=0;i<len;i++){
            int prod=res[i]*a+carry;
            res[i]=prod%10;
            carry=prod/10;
        }
        while(carry){
            res.push_back(carry%10);
            carry/=10;
            len++;
        }
    }
public:
    vector<int> factorial(int N){
        vector<int> res;
        res.push_back(1);
        int len=1;
        for(int i=2;i<=N;i++){
            mul(i,len,res);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends