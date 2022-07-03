
//union
int doUnion(int a[], int n, int b[], int m)  {
        unordered_set<int> lookup;
        for(int i=0;i<n;i++)lookup.insert(a[i]);
        for(int i=0;i<m;i++)lookup.insert(b[i]);
        return (int)lookup.size();
    }

//intersection
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> lookup;
        for(auto &x:nums1)lookup[x]=1;
        vector<int> intersect;
        for(auto &x:nums2){
            if(lookup[x]){
                lookup[x]=0;
                intersect.emplace_back(x);
            }
        }
        return intersect;
    }
};