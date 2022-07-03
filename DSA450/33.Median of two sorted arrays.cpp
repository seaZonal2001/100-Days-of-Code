class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        //O(n1+n2) time complexity and O(1) space
       /*
        int n1=nums1.size(),n2=nums2.size();
        int a=-1,b=-1;
        int pos=(n1+n2)/2;
        int i=0,j=0;
        if((n1+n2)&1){
            for(int k=0;k<=pos;k++){
                if(i<n1 && j<n2){
                    if(nums1[i]<=nums2[j])a=nums1[i++];
                    else a=nums2[j++];
                }else if(i<n1){
                    a=nums1[i++];
                }else{
                    a=nums2[j++];
                }
            }
            return double(a);
        }else{
            for(int k=0;k<=pos;k++){
                b=a;
                if(i<n1 && j<n2){
                    if(nums1[i]<=nums2[j])a=nums1[i++];
                    else a=nums2[j++];
                }else if(i<n1){
                    a=nums1[i++];
                }else{
                    a=nums2[j++];
                }
            }
            return double(a+b)/2;
        }
        
        */
        
        //O(log(min(n1,n2))) time complexity and O(1) space
        if(nums1.size()>nums2.size())return findMedianSortedArrays(nums2,nums1);
        
        int n1=nums1.size(),n2=nums2.size();
        
        int l=0,r=n1;
        while(l<=r){
            int cut1=(l+r)>>1;
            int cut2=(n1+n2+1)/2-cut1;
            
            int left1=(cut1==0?INT_MIN:nums1[cut1-1]);
            int left2=(cut2==0?INT_MIN:nums2[cut2-1]);
            
            int right1=(cut1==n1?INT_MAX:nums1[cut1]);
            int right2=(cut2==n2?INT_MAX:nums2[cut2]);
            
            if(left1<=right2 && left2<=right1){
                if((n1+n2)&1)
                    return double(max(left1,left2));
                else
                    return double(max(left1,left2)+min(right1,right2))/2;
            }else if(left1>right2){
                r=cut1-1;
            }else{
                l=cut1+1;
            }
        }
        return 0.0;
    }
};