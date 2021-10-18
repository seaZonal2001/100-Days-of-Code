#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void topo(int i,vector<int> adj[],vector<bool>& visited,stack<int>& st){
	    visited[i]=true;
	    for(auto v:adj[i]){
	        if(!visited[v]){
	            topo(v,adj,visited,st);
	        }
	    }
	    st.push(i);
	}
		void dfs2(int i,vector<int> adjT[],vector<bool>& visited){
	    visited[i]=true;
	    for(auto v:adjT[i]){
	        if(!visited[v]){
	            dfs2(v,adjT,visited);
	        }
	    }
	    
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> st;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                topo(i,adj,visited,st);
            }
        }
        vector<int> adjT[V];
        for(int i=0;i<V;i++){
           for(auto j:adj[i])adjT[j].push_back(i);
        }
        for(int i=0;i<V;i++)visited[i]=false;
        int scc=0;
        while(st.size()>0){
            int u=st.top();
            st.pop();
            if(!visited[u])
            dfs2(u,adjT,visited),scc++;
           
        }
        return scc;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends