#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    int maxAreaHistogram(vector<int> &nums){
        
        int n=nums.size();
        int maxArea=0;
        vector<int> st;
        
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || nums[st.back()]>=nums[i])){
                int height=nums[st.back()];
                st.pop_back();
                int width;
                if(st.empty())width=i;
                else width=i-st.back()-1;
                
                maxArea=max(maxArea,height*width);
            }
            st.push_back(i);
        }
        
        return maxArea;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> histogram(m,0);
        int maxArea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    histogram[j]=M[i][j];
                }else{
                    histogram[j]++;
                    if(M[i][j]==0)histogram[j]=0;
                }
            }
            maxArea=max(maxArea,maxAreaHistogram(histogram));
        }
        
        return maxArea;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends