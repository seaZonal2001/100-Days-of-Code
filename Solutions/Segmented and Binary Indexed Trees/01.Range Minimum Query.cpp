#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}
// } Driver Code Ends


/* The functions which 
builds the segment tree */
int build(int *tree,int *arr,int index,int s,int e){
    if(s==e){
        tree[index]=arr[s];
        return arr[s];
    }
    int mid=(s+e)/2;
    tree[index]=min(build(tree,arr,2*index,s,mid),build(tree,arr,2*index+1,mid+1,e));
    return tree[index];
}
int *constructST(int arr[],int n)
{
  //Your code here
  int *tree=new int[4*n+1];
  build(tree,arr,1,0,n-1);
  return tree;
}

int query(int *tree,int index,int s,int e,int a,int b){
    if(a<=s && b>=e)return tree[index];
    
    if(e<a || s>b)return INT_MAX;
    
    int mid=(s+e)/2;
    return min(query(tree,2*index,s,mid,a,b),query(tree,2*index+1,mid+1,e,a,b));
}
/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
//Your code here
    if(a<0 || b>n-1 || a>b)return -1;
    return query(st,1,0,n-1,a,b);
}