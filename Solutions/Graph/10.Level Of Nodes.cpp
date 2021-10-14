#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:

	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    vector<bool> visited(V,false);
	    queue<int> q;
	    q.push(0);
	    int level=0;
	    while(!q.empty()){
	        int n=q.size();
	        for(int i=0;i<n;i++){
	            int u=q.front();
	            visited[u]=true;
	            q.pop();
	            if(u==X)return level;
	            for(auto v:adj[u]){
	                if(!visited[v]){
	                    q.push(v);
	                }
	            }
	        }
	        level++;
	    }
	    return -1;
	    
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}

  // } Driver Code Ends