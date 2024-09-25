class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<int> majorityElements;
        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]]>nums.size()/3){
                if(majorityElements.size()<2){
                    if((majorityElements.empty() || majorityElements[0]!=nums[i]) ) majorityElements.push_back(nums[i]);
                }
            }
        }
    return majorityElements; 
}
};