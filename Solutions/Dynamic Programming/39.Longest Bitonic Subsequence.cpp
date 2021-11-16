#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size();
	    vector<int> LIS(n),LDS(n);
	    for(int i=0;i<n;i++){
	        LIS[i]=1;
	        for(int j=0;j<i;j++){
	            if(nums[j]<nums[i])
	                LIS[i]=max(LIS[i],LIS[j]+1);
	        }
	    }
	    for(int i=n-1;i>=0;i--){
	        LDS[i]=1;
	        for(int j=n-1;j>i;j--){
	            if(nums[j]<nums[i])
	                LDS[i]=max(LDS[i],LDS[j]+1);
	        }
	    }
	    int ans=0;
	    for(int i=0;i<n;i++){
	        ans=max(ans,LIS[i]+LDS[i]-1);
	    }
	    return ans;
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
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends