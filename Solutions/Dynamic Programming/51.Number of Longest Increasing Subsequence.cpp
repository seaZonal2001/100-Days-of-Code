class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),maxLen=1;
        vector<int> LIS(n,1),count(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(LIS[j]+1>LIS[i]){
                        LIS[i]=LIS[j]+1;
                        count[i]=count[j];
                    }else if(LIS[j]+1==LIS[i]){
                        count[i]+=count[j];
                    }
                }
            }
            maxLen=max(maxLen,LIS[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(LIS[i]==maxLen)
                ans+=count[i];
        }
        return ans;
    }
};