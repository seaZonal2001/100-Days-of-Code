#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int n;
int max(int a,int b){
    if(a>=b)return a;
    return b;
}
int profit(int arr[],int i,int j,int t,int dp[n][n]){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    
    int x=arr[i]*t+profit(arr,i+1,j,t+1,dp);
    int y=arr[j]*t+profit(arr,i,j-1,t+1,dp);
    return dp[i][j]=max(x,y);
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    int dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            dp[i][j]=-1;
    }
    int ans=profit(arr,0,n-1,1,dp);
    printf("%d",ans);
    
    return 0;
}
