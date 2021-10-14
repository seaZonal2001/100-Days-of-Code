#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    void dfs(vector<vector<char>>& grid,int i,int j,int n,int m){
        if(i<0 || j<0 | i>=n || j>=m)return  ;
        if(grid[i][j]=='O')return;
        grid[i][j]='O';
        for(int k=0;k<4;k++)dfs(grid,i+dx[k],j+dy[k],n,m);
    }
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int ans=0,n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X'){
                    ans++;
                    dfs(grid,i,j,n,m);
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
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends