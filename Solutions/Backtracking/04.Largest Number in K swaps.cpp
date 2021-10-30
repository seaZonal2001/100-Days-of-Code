#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string ans;
    void getMax(string &str,int k,int id){
       
        if(k==0)return ;
        
        char mx=str[id];
        for(int i=id+1;i<str.length();i++){
            if(mx<str[i])mx=str[i];
        }
        
        if(mx!=str[id])k--;
        for(int i=str.length()-1;i>=id;i--){
            if(str[i]==mx){
                swap(str[id],str[i]);
                if(str>ans)ans=str;
                getMax(str,k,id+1);
                swap(str[id],str[i]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       ans=str;
       getMax(str,k,0);
       return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends