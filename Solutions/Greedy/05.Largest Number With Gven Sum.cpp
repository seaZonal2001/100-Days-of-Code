#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        // Your code here
        if(n*9<sum)return "-1";
        int d[]={9,8,7,6,5,4,3,2,1};
        string ans;
        int cnt,i=0;
        char c;
        while(sum>0 && i<9){
            cnt=sum/d[i];
            c=(char)(d[i]+'0');
            for(int j=0;j<cnt;j++)ans+=c;
            sum-=cnt*d[i];
            i++;
        }
        n-=ans.length();
        while(n--)ans+='0';
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends