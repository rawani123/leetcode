class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int positive=0,negitive=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans[positive]=nums[i];
                positive+=2;
            }else{
                ans[negitive]=nums[i];
                negitive+=2;
            }
        }
        return ans;
    }
};