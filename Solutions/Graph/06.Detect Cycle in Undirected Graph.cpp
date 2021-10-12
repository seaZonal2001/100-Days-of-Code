#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int> adj[],int i,vector<bool> &visited,int parent){
        visited[i]=true;
        
        for(auto x:adj[i]){
            if(!visited[x]){
                if(dfs(adj,x,visited,i))
                return true;
            }else if(x!=parent){
                return true;
            }
        }
        return false;
    }
    bool bfs(vector<int> adj[],int i,vector<bool> &visited,int V){
        vector<int> parent(V,-1);
        queue<int> q;
        q.push(i);
        visited[i]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:adj[u]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                    parent[v]=u;
                }else if(v!=parent[u]){
                    return true;
                }
            }
           
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                //if(bfs(adj,i,visited,V))return true;
                if(dfs(adj,i,visited,-1))return true;
            }
        }
       
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends