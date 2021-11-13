class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>> LCS(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s[n-j])
                    LCS[i][j]=1+LCS[i-1][j-1];
                else
                    LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
        return LCS[n][n];
    }
};