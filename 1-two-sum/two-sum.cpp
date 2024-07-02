class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int firstDigit=nums[i];
            int remaing=target-firstDigit;
            if(mpp.find(remaing)!=mpp.end()){
                return {mpp[remaing],i};
            }
            mpp[firstDigit]=i;
        }
        return {-1,-1};
    }
};