class Solution {
public:
    void dfs(int u,vector<int> adj[],vector<bool>& visited,vector<int>& disco,vector<int>& low,vector<int>& parent,vector<vector<int>>& ans,int &time){
        disco[u]=time,low[u]=time;
        time++;
        visited[u]=true;
        
        for(auto v:adj[u]){
            if(v==parent[u]){
                continue;
            }else if(visited[v]==true){
                low[u]=min(low[u],disco[v]);
            }else{
                parent[v]=u;
               
                dfs(v,adj,visited,disco,low,parent,ans,time);
                low[u]=min(low[u],low[v]);
                
                if(low[v]>disco[u]){
                   ans.push_back({u,v});
                }
            }
        }
    }    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<vector<int>> ans;
        vector<bool> visited(n,false);
        vector<int>parent(n),disco(n),low(n);
        int time=0;
        parent[0]=-1;
        dfs(0,adj,visited,disco,low,parent,ans,time);
        
        
        return ans;
    }
};