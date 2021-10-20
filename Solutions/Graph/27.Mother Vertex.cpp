#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int u,vector<int> adj[],vector<bool>& visited,stack<int>& st){
        visited[u]=true;
        for(auto v:adj[u]){
            if(!visited[v]){
                dfs(v,adj,visited,st);
            }
        }
        st.push(u);
    }
    void check(int u,vector<int> adj[],vector<bool>& visited,int &count){
        visited[u]=true;
        count++;
        for(auto v:adj[u]){
            if(!visited[v]){
                check(v,adj,visited,count);
            }
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    stack<int> st;
	    vector<bool> visited(V,false);
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            dfs(i,adj,visited,st);
	        }
	    }
	    int ans=st.top();
	    for(int i=0;i<V;i++)visited[i]=false;
	    int count=0;
	    check(ans,adj,visited,count);
	    if(count==V)return ans;
	    return -1;
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;