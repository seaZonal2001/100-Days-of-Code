class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //first approach - hashmap -> store frequency and return element with frequency>1
        
        //second approach - we can use the given array as a hashmap and toggle the sign of element
        //present at index (abs(arr[i])-1) if element at this index turn out to be positive that means current element is repeated;
        int sz=nums.size();
        for(int i=0;i<sz;i++){
            int index=abs(nums[i])-1;
            nums[index]*=-1;
            if(nums[index]>0)return abs(nums[i]);
        }
        return -1;
    }
};