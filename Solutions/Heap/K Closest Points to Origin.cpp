#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<vector<int>> KClosest(vector<vector<int>> &points,int k){
        int n=points.size();
        priority_queue<tuple<int,int,int>> pq;
        int d;
        for(int i=0;i<n;i++){
            d=(points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            pq.emplace(make_tuple(d,points[i][0],points[i][1]));
            if(pq.size()>k)pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto i=pq.top();
            pq.pop();
            ans.push_back({get<1>(i),get<2>(i)});
        }
        return ans;   
    }
};
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        int n,k;cin>>n>>k;
        vector<vector<int>> points(n,vector<int>(2));
        for(int i=0;i<n;i++)cin>>points[i][0]>>points[i][1];

        Solution obj;
        vector<vector<int>> result=obj.KClosest(points,k);
        for(auto i:result)cout<<i[0]<<" "<<i[1]<<'\n';
    }
}