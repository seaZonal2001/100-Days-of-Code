class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int res=nums[0];
        int lmin=res,lmax=res;
        
        for(int i=1;i<n;i++){
            if(nums[i]<0)
                swap(lmin,lmax);
            
            lmax=max(nums[i],lmax*nums[i]);
            lmin=min(nums[i],lmin*nums[i]);
            
            res=max(res,lmax);
        }
        return res;
    }
};