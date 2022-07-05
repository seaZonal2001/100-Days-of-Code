// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends

struct Node{
    int val,x,y;
    Node(int val=0,int x=0,int y=0):val(val),x(x),y(y){}
};

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    
    //O (n*n*log(k))
  /*
  priority_queue<int> pq;
  for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          pq.emplace(mat[i][j]);
          if(pq.size()>k)pq.pop();
      }
  }
  
  return pq.top();
  */
  
  // O(klog(n))
  
  auto comp = [&](Node &a,Node &b){
        return a.val>b.val;  
  };
  
  priority_queue<Node,vector<Node>,decltype(comp)> pq(comp);
  
  for(int i=0;i<n;i++)pq.push({mat[i][0],i,0});
  
  for(int i=1;i<k;i++){
      int x=pq.top().x,y=pq.top().y;
      pq.pop();
      if(y+1<n){
          pq.push({mat[x][y+1],x,y+1});
      }
  }
  
  return pq.top().val;
}
