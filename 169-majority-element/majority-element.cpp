class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int majorityElement;
        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]]>nums.size()/2){
                majorityElement=nums[i];
            }
        }
        return majorityElement; 
    }
};