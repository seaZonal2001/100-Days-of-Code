class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int r=-1;
        sort(intervals.begin(),intervals.end());
        for(auto &x:intervals){
            if(x[0]>r){
                res.push_back(x);
                r=x[1];
            }else{
                r=max(r,x[1]);
                res.back()[1]=r;
            }
        }
        return res;
    }
};