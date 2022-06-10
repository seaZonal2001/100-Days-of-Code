class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<int> q;
        vector<int> color(n,0);
        for(int i=0;i<n;i++){
            if(color[i])continue;
            color[i]=1;
            for(q.push(i);!q.empty();q.pop()){
                int curr=q.front();
                for(auto &neighbour:graph[curr]){
                    if(!color[neighbour]){
                        color[neighbour]=-color[curr],q.push(neighbour);
                    }else if(color[neighbour]==color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};