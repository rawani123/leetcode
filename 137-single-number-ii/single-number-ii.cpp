class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<long long,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        } 
        int nonRepeated=0;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==1){
                nonRepeated=nums[i];
            }
        } 
        return nonRepeated;

    }
};