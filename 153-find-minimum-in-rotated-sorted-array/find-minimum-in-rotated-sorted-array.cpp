class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[low]<=nums[high]){
                ans=min(ans,nums[low]);
                break;
            }
            if(nums[low]<=nums[mid]){
                ans=min(nums[low],ans);
                low = mid+1;
            }else{
                high=mid-1;
                ans=min(nums[mid],ans);
            }
        }
        return ans;
    }
};