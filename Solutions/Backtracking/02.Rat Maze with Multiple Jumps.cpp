#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    bool isSafe(vector<vector<int>>& matrix,int i,int j,int n){
        if(i<n && j<n && matrix[i][j]!=0)return true;
        return false;
    }
    bool generatePath(vector<vector<int>> &matrix,int n,vector<vector<int>> &path,int i=0,int j=0){
        if(i==n-1 && j==n-1){path[i][j]=1;return true;}
        if(isSafe(matrix,i,j,n)){
            
        path[i][j]=1;
        for(int k=1;k<=matrix[i][j] && k<n;k++){
                
                
                 
                if(generatePath(matrix,n,path,i,j+k))return true;
            
            
                if(generatePath(matrix,n,path,i+k,j))return true;
                
                
            
        }
        path[i][j]=0;
        
        }
       
        
        
        return false;
        
    }
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   // Code here
	   int n=matrix.size();
	   vector<vector<int>> path(n,vector<int>(n,0));
	   
	   if(generatePath(matrix,n,path)){
	        return path;
	   }
	   else
	   return {{-1}};
 	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends