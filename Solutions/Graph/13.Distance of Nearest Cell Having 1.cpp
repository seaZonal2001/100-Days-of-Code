#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    //bfs approach
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size(),m=grid[0].size();
	    vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
	    queue<pair<int,int>> q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                q.emplace(i,j);
	                ans[i][j]=0;
	            }
	        }
	    }
	    int dx[]={0,0,-1,1};
	    int dy[]={-1,1,0,0};
	    while(!q.empty()){
	        int x=q.front().first;
	        int y=q.front().second;
	        q.pop();
	        for(int i=0;i<4;i++){
	            int nx=x+dx[i];
	            int ny=y+dy[i];
	            if(nx>=0 && ny>=0 && nx<n && ny<m){
	                if(ans[nx][ny]>ans[x][y]+1){
	                    ans[nx][ny]=1+ans[x][y];
	                    q.emplace(nx,ny);
	                }
	            }
	        }
	        
	        
	    }
	    return ans;
	}

    //dynamic programming approach
    vector<vector<int>>nearest(vector<vector<int>>mat)
	{
	    // Code here
	   int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int> (m,INT_MAX-1));
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(mat[i][j]==1)
                    ans[i][j]=0;
            }
        }
        
         for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(mat[i][j]!=1)
                {
                    if(j-1>=0)
                        ans[i][j]=min(ans[i][j],ans[i][j-1]+1);
                    
                    if(i-1>=0)
                        ans[i][j]=min(ans[i][j],ans[i-1][j]+1); 
                    
                    if(j+1<m)
                        ans[i][j]=min(ans[i][j],ans[i][j+1]+1);
                    
                    if(i+1<n)
                        ans[i][j]=min(ans[i][j],ans[i+1][j]+1);
                }
            }
        }
        
         for(int i=n-1;i>=0;--i)
        {
            for(int j=m-1;j>=0;--j)
            {
                if(mat[i][j]!=1)
                {
                    if(j-1>=0)
                        ans[i][j]=min(ans[i][j],ans[i][j-1]+1);
                    
                    if(i-1>=0)
                        ans[i][j]=min(ans[i][j],ans[i-1][j]+1); 
                    
                    if(j+1<m)
                        ans[i][j]=min(ans[i][j],ans[i][j+1]+1);
                    
                    if(i+1<n)
                        ans[i][j]=min(ans[i][j],ans[i+1][j]+1);
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends