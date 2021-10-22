#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i].first=start[i],v[i].second=end[i];
        }
        sort(v.begin(),v.end(),[](pair<int,int>& a,pair<int,int>& b){
           return a.second<b.second; 
        });
        
        int count=1;
        int prev=0;
        for(int i=1;i<n;i++){
            if(v[i].first>v[prev].second){
                count++;
                prev=i;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends