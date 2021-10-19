//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int time=0;
    vector<int> disco,low,parent;
    vector<bool> visited,ap;
    void dfs(int u,vector<int> adj[]){
        disco[u]=time,low[u]=time;
        time++;
        visited[u]=true;
        
        int count=0; //will help to decide whether root isan artculation point or not.
        for(auto v:adj[u]){
            if(parent[u]==v){
                continue;
            }else if(visited[v]==true){
                low[u]=min(low[u],disco[v]);//reachabe to it ancestor (!parent)
            }else{
                parent[v]=u;
                count++;
                dfs(v,adj);
                low[u]=min(low[u],low[v]); //if child node in dfs tree is reachable to its parents ancestor
                
                if(parent[u]==-1){
                    if(count>=2){ //if there are more than 1 child of root in dfs tree
                        ap[u]=true;
                    }
                }else if(low[v]>=disco[u]){ //if current node's child cannot reach it ancestor through another path
                    ap[u]=true;
                }
            }
        }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        disco.resize(V),low.resize(V),parent.resize(V),visited.resize(V,false),ap.resize(V,false);
        parent[0]=-1;
        dfs(0,adj);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(ap[i]==true)
            ans.push_back(i);
        }
        if(ans.size()==0)return {-1};
        return ans;
    }
};

// { Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends