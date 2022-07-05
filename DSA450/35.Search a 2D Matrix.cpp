class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        
        //Time complexity O(n*m)
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==target)return true;
            }
        }
        */
        
        //Time complexity O(n+m);
        /*
        int i=0,j=m-1;
        while(i<n && j>=0){
            if(matrix[i][j]==target)return true;
            else if(matrix[i][j]<target)i++;
            else j--;
        }
        */
        
        //Time complexity O(n+log(m))
        /*
        int row=-1;
        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target && matrix[i][m-1]>=target){
                row=i;
                break;
            }
        }
        if(row!=-1){
            int l=0,r=m-1;
            while(l<=r){
                int mid=(l+r)>>1;
                if(matrix[row][mid]==target)return true;
                else if(matrix[row][mid]<target)l=mid+1;
                else r=mid-1;
            }
        }
        */
        
        //Time complexity O(log(n)+log(m))
        int row=-1;
        int l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(matrix[mid][0]<=target){
                row=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        if(row!=-1){
            l=0,r=m-1;
            while(l<=r){
                int mid=(l+r)>>1;
                if(matrix[row][mid]==target)return true;
                else if(matrix[row][mid]<target)l=mid+1;
                else r=mid-1;
            }
        }
        
        return false;
        
    }
};