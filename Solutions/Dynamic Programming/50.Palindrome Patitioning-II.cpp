class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        vector<int> minCut(n+1,0);
        for(int i=0;i<=n;i++)minCut[i]=i-1;
        for(int i=0;i<n;i++){
            for(int j=0;i-j>=0 && i+j<n && s[i-j]==s[i+j];j++) //odd length
                minCut[i+j+1]=min(minCut[i+j+1],minCut[i-j]+1);
            
            for(int j=1;i-j+1>=0 && i+j<n && s[i-j+1]==s[i+j];j++) //Even Length
                minCut[i+j+1]=min(minCut[i+j+1],minCut[i-j+1]+1);
        }
        return minCut[n];
    }
};