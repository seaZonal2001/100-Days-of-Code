class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int arrows=0,n=points.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i].first=points[i][1],v[i].second=points[i][0];
        }
        sort(v.begin(),v.end());
        
        long last_point=LONG_MIN;
        int l,r;
        for(int i=0;i<n;i++){
            l=v[i].second;
            r=v[i].first;
            if(l>last_point){
                last_point=r;
                arrows++;
            }
        }
        return arrows;
    }
};