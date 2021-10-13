#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[],vector<bool>& visited,vector<bool>& recSt,int src){
        visited[src]=true;
        recSt[src]=true;
        for(auto v:adj[src]){
            if(!visited[v]){
                if(dfs(adj,visited,recSt,v))return true;
            }else if(recSt[v]==true)return true;
        }
        recSt[src]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V),recSt(V);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(adj,visited,recSt,i))return true;
            }
        }
        return false;
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends