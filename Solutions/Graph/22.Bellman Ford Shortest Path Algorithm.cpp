#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> path(n,INT_MAX);
	    int m=edges.size();
	    
	    path[0]=0;
	    for(int i=0;i<n-1;i++){
	        for(int j=0;j<m;j++){
	            int u=edges[j][0],v=edges[j][1],w=edges[j][2];
	            if(path[u]==INT_MAX)continue;
	            if(path[u]+w<path[v])
	            path[v]=path[u]+w;
	        }
	    }
	    for(int i=0;i<m;i++){
	        int u=edges[i][0],v=edges[i][1],w=edges[i][2];
	        if(path[u]==INT_MAX)continue;
	            if(path[u]+w<path[v])
	            return true;
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends