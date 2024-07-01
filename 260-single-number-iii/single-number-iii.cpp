class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> singleElements;
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]]==1){
                singleElements.push_back(nums[i]);
            }
        }
        return singleElements;

    }
};