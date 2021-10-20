#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
   map<pair<int,int>,bool> mp;
    //Function to find if the given edge is a bridge in graph.
    void dfs(int u,vector<int> adj[],vector<bool>& visited){
        visited[u]=true;
        for(auto v:adj[u]){
            if(!visited[v] && mp.find({u,v})==mp.end())
            dfs(v,adj,visited);
        }
    }
  
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<bool> visited(V,false);
        dfs(c,adj,visited);
        mp[{c,d}]=1,mp[{d,c}]=1;
        vector<bool> visitedM(V,false);
        dfs(c,adj,visitedM);
        for(int i=1;i<V;i++){
            if(visitedM[i]!=visited[i])return true;;
        }
        return false;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends