#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int source,vector<vector<int>>& graph,int destination,vector<int>& temp,vector<vector<int>>& ans){
        temp.push_back(source);
        if(source==destination){
            ans.push_back(temp);
            return;
        }
        
        for(auto v:graph[source]){
            dfs(v,graph,destination,temp,ans);
            temp.pop_back();
        }
         
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=graph.size()-1;
        dfs(0,graph,n,temp,ans);
        return ans;
    }
};

int main(){
    int V;cin>>V;
    vector<vector<int>> graph(V);
    int vertex,neighbour;
    for(int i=0;i<V;i++){
        cin>>neighbour;
        for(int j=0;j<neighbour;j++){
            cin>>vertex;
            graph[i].push_back(vertex);
        }
    }
    Solution obj;
    vector<vector<int>> res=obj.allPathsSourceTarget(graph);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
}