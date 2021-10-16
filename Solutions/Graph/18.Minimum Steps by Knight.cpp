#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    class Pair{
      public:
      int x,y,d;
      Pair(int x,int y,int d){
          this->x=x;
          this->y=y;
          this->d=d;
      }
    };
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    queue<Pair> q;
	    q.emplace(Pair(KnightPos[0]-1,KnightPos[1]-1,0));
	    
	    vector<vector<bool>> visited(N,vector<bool>(N,false));
	    visited[KnightPos[0]-1][KnightPos[1]-1]=true;
	    int dx[]={-1,1,-2,-2,-1,1,2,2},dy[]={2,2,1,-1,-2,-2,1,-1};
	    int res=INT_MAX;
	    while(!q.empty()){
	        int cx=q.front().x,cy=q.front().y,cd=q.front().d;
	        q.pop();
	        
	        if(cx==TargetPos[0]-1 && cy==TargetPos[1]-1){
	           res=min(res,cd);
	           continue;
	        }
	        
	        for(int i=0;i<8;i++){
	            int nx=cx+dx[i],ny=cy+dy[i];
	            if(nx>=0 && ny>=0 && nx<N && ny<N){
	                if(!visited[nx][ny]){
	                    q.emplace(Pair(nx,ny,cd+1));
	                    visited[nx][ny]=true;
	                }
	            }
	        }
	    }
	    return res;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends