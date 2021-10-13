#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool dfs(vector<vector<int>>& grid,int i,int j,int n){
        if(i<0 || j<0 || i>=n || j>=n)return false;
        if(grid[i][j]==0)return false;
        if(grid[i][j]==2)return true;
        grid[i][j]=0;
       
        if(dfs(grid,i,j-1,n) || dfs(grid,i,j+1,n) || dfs(grid,i-1,j,n) || dfs(grid,i+1,j,n))
        return true;
        
        return false;
        
        
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(grid[i][j]==1){
             return dfs(grid,i,j,n);
        }
       
       return false;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends