class Solution {
public:
    int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
    void getResult(vector<vector<int>>& grid,int sx,int sy,int ex,int ey,int count,vector<vector<bool>>& visited,int &ans){  if(sx<0 || sy<0 || sx>=grid.size() || sy>=grid[0].size() || visited[sx][sy] || grid[sx][sy]==-1)return;
        if(count==0){
            if(sx==ex && sy==ey){
                ans++;
            }
            return;
        }
        if(sx==ex && sy==ey && count)return;
        
        visited[sx][sy]=true;
        for(int i=0;i<4;i++){
        int nx=sx+dx[i],ny=sy+dy[i];
        getResult(grid,nx,ny,ex,ey,count-1,visited,ans);

        }                                                                                                                    
 visited[sx][sy]=false;

    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int sx,sy,ex,ey,count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)sx=i,sy=j;
                else if(grid[i][j]==2)ex=i,ey=j,count++;
                else if(grid[i][j]!=-1)count++;
                
            }
        }
        int ans=0;
        getResult(grid,sx,sy,ex,ey,count,visited,ans);
        return ans;
    }
};