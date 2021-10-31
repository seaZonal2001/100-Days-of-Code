#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    void generateSubsets(vector<int>& arr,int i,vector<int>& temp,set<vector<int>>& uni){
        if(i==arr.size()){
            uni.insert(temp);
            return;
        }
        
        generateSubsets(arr,i+1,temp,uni);
        temp.push_back(arr[i]);
        generateSubsets(arr,i+1,temp,uni);
        temp.pop_back();
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        vector<vector<int>> ans;
        vector<int> temp;
        set<vector<int>> uni;
        sort(arr.begin(),arr.end());
        generateSubsets(arr,0,temp,uni);
        for(const auto &i:uni)
        ans.push_back(i);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends