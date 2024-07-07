class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        double leftProduct=1;
        double rightProduct=1;
        double maxProduct=nums[0];
        for(int i=0;i<nums.size();i++){
            leftProduct=leftProduct==0 ? 1 : leftProduct;
            rightProduct=rightProduct==0?1:rightProduct;
            leftProduct*=nums[i];
            rightProduct*=nums[nums.size()-1-i];
            maxProduct=max(maxProduct,max(leftProduct,rightProduct));
        }
        return maxProduct;
    }
};