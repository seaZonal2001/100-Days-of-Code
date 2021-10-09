#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{   priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(right.size()>0 && x>right.top())right.push(x);
        else left.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        int l=left.size(),r=right.size();
        if(l-r>1)right.push(left.top()),left.pop();
        else if(r-l>1)left.push(right.top()),right.pop();
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(left.size()==right.size())return (double)(left.top()+right.top())/2;
        else if(left.size()>right.size())return (double)left.top();
        return (double)right.top();
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends