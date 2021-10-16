#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n=nums.size();
	    vector<pair<int,int>> v(n);
	    for(int i=0;i<n;i++)v[i].first=nums[i],v[i].second=i;
	    sort(v.begin(),v.end());
	    int swaps=0;
	    vector<bool> visited(n,false);
	    for(int i=0;i<n;i++){
	        if(v[i].second==i || visited[i])continue;
	        
	        int cycleLen=0;
	        int j=i;
	        while(!visited[j]){
	            visited[j]=true;
	            j=v[j].second;
	            cycleLen++;
	        }
	        swaps+=cycleLen-1;
	    }
	    return swaps;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends