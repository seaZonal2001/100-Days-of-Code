class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        // main diagonal as mirror
        for(int i=0;i<n;i++){
            for(int j=1;i-j>=0;j++){
                swap(matrix[i-j][i],matrix[i][i-j]);
            }
        }
        
        //left boundary as mirror
        for(int i=0;i<n;i++){
            int l=0,r=n-1;
            while(l<r)swap(matrix[i][l++],matrix[i][r--]);
        }
    }
};