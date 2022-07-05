//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
    int getCount(vector<vector<int>> &matrix,int r,int c,int x){
        int count=0;
        for(int i=0;i<r;i++){
            count+=(upper_bound(matrix[i].begin(),matrix[i].end(),x)-matrix[i].begin());
        }
        return count;
    }
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        int maxEl=INT_MIN,minEl=INT_MAX;
        for(int i=0;i<r;i++){
            maxEl=max(maxEl,matrix[i][c-1]);
            minEl=min(minEl,matrix[i][0]);
        }
        int n=r*c/2;
        while(minEl<=maxEl){
            int mid=(minEl+maxEl)>>1;
            int count=getCount(matrix,r,c,mid);
            if(count<=n){
                minEl=mid+1;
            }else{
                maxEl=mid-1;
            }
        }
        
        return minEl;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends