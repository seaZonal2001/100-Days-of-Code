class Solution {
public:
    vector<int> parent,rank;
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }
    void uni(int x,int y){
        int _x=find(x),_y=find(y);
        if(_x==_y)return ;
        if(rank[_x]<rank[_y])
            parent[_x]=_y;
        else if(rank[_x]>rank[_y])
            parent[_y]=_x;
        else
            parent[_y]=_x,rank[_x]++;
    }
    int largestComponentSize(vector<int>& nums) {
        int size=*max_element(nums.begin(),nums.end());
        parent.resize(size+1);
        rank.resize(size+1,0);
        for(int i=0;i<size+1;i++)parent[i]=i;
        
        for(int i=0;i<nums.size();i++){
            for(int j=2;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    uni(nums[i],j);
                    uni(nums[i]/j,j);
                }
            }
        }
        unordered_map<int,int> freq;
        int res=0;
        for(auto x:nums){
            res=max(res,++freq[find(x)]);
        }
        return res;
    }
};