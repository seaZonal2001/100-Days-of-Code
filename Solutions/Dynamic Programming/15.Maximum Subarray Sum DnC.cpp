class Solution {
public:
    struct sumData{
      int preSum,suffSum,maxSum,sum;
      sumData():preSum(0),suffSum(0),maxSum(0),sum(0){}
      sumData(int val):preSum(val),suffSum(val),maxSum(val),sum(val){}
      
    };
    sumData getMax(vector<int>& nums,int l,int r){
        if(l>r)return sumData();
        if(l==r)return sumData(nums[l]);
        
        int mid=(l+r)/2;
        
        sumData left=getMax(nums,l,mid);
        sumData right=getMax(nums,mid+1,r);
        
        sumData result;
        result.preSum=max(left.preSum,left.sum+right.preSum);
        result.suffSum=max(right.suffSum,right.sum+left.suffSum);
        result.sum=left.sum+right.sum;
        result.maxSum=max(left.suffSum+right.preSum,max(left.maxSum,right.maxSum));
        
        return result;
    }
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        
        return getMax(nums,0,n-1).maxSum;
    }
};