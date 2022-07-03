class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos=nums.size()-2;
        while(pos>=0 && nums[pos+1]<=nums[pos])pos--;
        if(pos>=0){
            int i=nums.size()-1;
            while(nums[i]<=nums[pos])i--;
            swap(nums[i],nums[pos]);
        }
        reverse(nums.begin()+pos+1,nums.end());
    }
};