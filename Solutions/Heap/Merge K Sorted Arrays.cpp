#include<bits/stdc++.h>
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

class Solution
{
    public:
   
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        
       priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
       for(int i=0;i<K;i++)pq.emplace(make_tuple(arr[i][0],i,0));
       vector<int> ans;
       
      while(!pq.empty()){
          int val,i,j;
          auto it=pq.top();
          pq.pop();
          val=get<0>(it),i=get<1>(it),j=get<2>(it);
         
          ans.push_back(val);
          j++;
          if(j!=K)pq.emplace(make_tuple(arr[i][j],i,j));
      }
       return ans;
    }
};



int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(N, vector<int> (N, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}
