#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
    void dfs(vector<vector<int>>& image,int source,int sr,int sc,int newColor){
        if(newColor==source)return;
        image[sr][sc]=newColor;
        
        for(int i=0;i<4;i++){
            int nx=sr+dx[i],ny=sc+dy[i];
            if(nx>=0 && ny>=0 && nx<image.size() && ny<image[0].size() && image[nx][ny]==source){
                dfs(image,source,nx,ny,newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int source = image[sr][sc];
        dfs(image,source,sr,sc,newColor);
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends