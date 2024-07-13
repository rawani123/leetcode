class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];
        int i=1,j=nums.size()-2;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            if((mid%2==1 && nums[mid-1]==nums[mid]) || mid%2==0 && nums[mid+1]==nums[mid]){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return -1;
    }
};