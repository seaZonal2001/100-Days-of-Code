#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
    vector<bool> visited(V,false);
    pq.emplace(make_tuple(0,0,-1));
    int weight=0;
    while(!pq.empty()){
        auto i=pq.top();
        pq.pop();
        if(visited[get<1>(i)])continue;
        weight+=get<0>(i);
        visited[get<1>(i)]=true;
        for(int j=0;j<adj[get<1>(i)].size();j++){
            if(!visited[adj[get<1>(i)][j][0]]){
                pq.emplace(make_tuple(adj[get<1>(i)][j][1],adj[get<1>(i)][j][0],get<1>(i)));
            }
        }
    }
    return weight;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends