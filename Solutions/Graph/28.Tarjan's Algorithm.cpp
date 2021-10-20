#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<int> disco,low;
    vector<bool> currSt;
    stack<int> path;
    int timer=0;
    void dfs(int u,vector<int> adj[],vector<vector<int>> & ans){
        disco[u]=low[u]=timer;
        timer++;
        currSt[u]=true;
        path.push(u);
        for(auto v:adj[u]){
            if(disco[v]==-1){
                dfs(v,adj,ans);
                low[u]=min(low[v],low[u]);
            }else if(currSt[v]){
                low[u]=min(low[u],disco[v]);
            }
        }
        if(low[u]==disco[u]){
            vector<int> temp;
            while(path.top()!=u){
                currSt[path.top()]=false;
                temp.push_back(path.top());
                path.pop();
            }
            currSt[path.top()]=false;
            temp.push_back(path.top());
            path.pop();
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
    }
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        vector<vector<int>> ans;
        disco.resize(V,-1),low.resize(V,-1),currSt.resize(V,false);
        for(int i=0;i<V;i++){
            if(disco[i]==-1){
                dfs(i,adj,ans);
            }
        }
       
        sort(ans.begin(),ans.end());
        return ans;
        
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
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends