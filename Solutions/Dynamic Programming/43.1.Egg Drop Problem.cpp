//DP + Binary Search

lass Solution {
public:
    int superEggDrop(int e, int f) {
        vector<vector<int>> dp(e+1,vector<int>(f+1,0));
        for(int i=0;i<=e;i++)
            dp[i][0]=0,dp[i][1]=1;
        for(int i=0;i<=f;i++)
            dp[0][i]=0,dp[1][i]=i;
        
        for(int i=2;i<=e;i++){
            for(int j=2;j<=f;j++){
                int l=1,r=j,temp,ans=INT_MAX;
                while(l<=r){
                    int mid=(l+r)/2;
                    int left=dp[i-1][mid-1]; //Egg breaks
                    int right=dp[i][j-mid]; //Egg Doesnt Breaks
                    temp=1+max(left,right);
                    if(left<right)
                        l=mid+1;
                    else
                        r=mid-1;
                    ans=min(ans,temp);
                }
                dp[i][j]=ans;
            }
        }
        return dp[e][f];
        
    }
};

//Mathematical Solution
class Solution {
public:
    int superEggDrop(int e, int f) {
       int l=1,r=f;
        while(l<r){
            int mid=(l+r)/2;
            if(fun(mid,e,f)<f)
                l=mid+1;
            else
                r=mid;
        }
        return l;
    }
    int fun(int x,int e,int f){
        int ans=0,r=1;
        for(int i=1;i<=e;i++){
            r*=(x-i+1);
            r/=i;
            ans+=r;
            if(ans>=f)break;
        }
        return ans;
    }
};

