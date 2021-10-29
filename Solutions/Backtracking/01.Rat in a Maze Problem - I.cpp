#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
    char p[4]={'L','R','U','D'};
    void generatePath(vector<vector<int>> &m,int n,string path,int i=0,int j=0){
        if(i<0 || j<0 || i>=n || j>=n)return;
        if(m[i][j]==0)return;
        if(i==n-1 && j==n-1){
            ans.push_back(path);
            return;
        }
        m[i][j]=0;
        for(int k=0;k<4;k++){
            int nx=i+dx[k],ny=j+dy[k];
            if(nx>=0 && ny>=0 && nx<n && ny<n){
                
                generatePath(m,n,path+p[k],nx,ny);
                
            }
        }
        m[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        generatePath(m,n,"");
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends