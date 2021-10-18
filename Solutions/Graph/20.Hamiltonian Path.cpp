#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    bool dfs(int src,vector<int> adj[],set<int>& path,int &N){
        if(path.size()==N-1){
            return true;
        }
        path.insert(src);
        for(auto v:adj[src]){
            if(path.find(v)==path.end()){
                if(dfs(v,adj,path,N))return true;
            }
        }
        path.erase(src);
        return false;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        vector<int> adj[N+1];
        for(int i=0;i<M;i++){
            adj[Edges[i][0]].push_back(Edges[i][1]);
            adj[Edges[i][1]].push_back(Edges[i][0]);
        }
        set<int> path;
        for(int i=1;i<=N;i++){
            
            if(dfs(i,adj,path,N))return true;
           
        }
        return false;
    }
};
 

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}  // } Driver Code Ends