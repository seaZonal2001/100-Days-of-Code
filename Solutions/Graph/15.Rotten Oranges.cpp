#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        int nRot=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                q.emplace(i,j);
                else if(grid[i][j]==1)nRot++;
            }
        }
        int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
        
        int ans=-1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int x=q.front().first,y=q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int nx=x+dx[j],ny=y+dy[j];
                    if(nx>=0 && ny>=0 && nx<n && ny<m){
                        if(grid[nx][ny]==1){
                            nRot--;
                            grid[nx][ny]=2;
                            q.emplace(nx,ny);
                        }
                    }
                }
            }
            ans++;
        }
        if(nRot)return -1;
        if(ans==-1)return 0;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends