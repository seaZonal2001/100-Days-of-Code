#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(int node,int V,vector<int>& color,bool graph[101][101],int col){
    for(int i=0;i<V;i++){
        if(i!=node && graph[i][node] && color[i]==col)return false;
    }
    return true;
}
bool possible(int node,int m,int V,vector<int>& color,bool graph[101][101]){
    if(node==V)
    return true;
    
    for(int col=1;col<=m;col++){
        if(isSafe(node,V,color,graph,col)){
            color[node]=col;
            if(possible(node+1,m,V,color,graph))return true;
            color[node]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    vector<int> color(V,0);
    if(possible(0,m,V,color,graph))return true;
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends