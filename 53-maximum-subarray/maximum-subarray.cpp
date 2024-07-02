class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
    //     int maxi=INT_MIN;
    //     int sum=0;
        
    //     for(int i=0;i<nums.size();i++){

    //         sum+=nums[i];
            
    //         if(sum>=0 && sum>maxi){
    //             maxi=sum;
    //         }
    //         if(sum<0){
    //             sum=0;
    //         }
    //     }
    //     if(maxi==INT_MIN){
    //         return -1;
    //     }
    //     return maxi;
    // }
 
    int maxSubArray(std::vector<int>& nums) {
        int maxi = nums[0];
        int sum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            sum = max(nums[i], sum + nums[i]);
            maxi = max(maxi, sum);
        }
        
        return maxi;
    }
};
