#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int dx[8]={0,0,-1,1,-1,-1,1,1},dy[8]={-1,1,0,0,-1,1,-1,1};
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m,int& area){
        if(i<0 || j<0 || i>=n || j>=m)return;
        
        if(grid[i][j]==0)return;
        
        area++;
        grid[i][j]=0;
        
        for(int k=0;k<8;k++){
            
            dfs(grid,i+dx[k],j+dy[k],n,m,area);
        }
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans=-1,area=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    area=0;
                    dfs(grid,i,j,n,m,area);
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends