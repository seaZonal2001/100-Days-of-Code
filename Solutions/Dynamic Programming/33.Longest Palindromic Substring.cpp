class Solution {
public:
    string longestPalindrome(string s) {
       int n=s.length();
       vector<vector<bool>> dp(n,vector<bool>(n,false));
       int id=0,len=1;
       for(int sz=1;sz<=n;sz++){
           for(int i=0;i+sz-1<n;i++){
               if(sz<2)
                   dp[i][i]=true;
               else if(sz==2)
                   dp[i][i+sz-1]=(s[i]==s[i+sz-1]);
               else
                   dp[i][i+sz-1]=(s[i]==s[i+sz-1] && dp[i+1][i+sz-2]);
               if(dp[i][i+sz-1])
                   id=i,len=sz;
           }
       }
        return s.substr(id,len);
    }
};