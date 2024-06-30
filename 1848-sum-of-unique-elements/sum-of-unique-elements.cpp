class Solution {
public:
  int sumOfUnique(vector<int>& nums) {
      unordered_map<int,int> mp;
      int lengthArray=nums.size();
      for(int i=0;i<lengthArray;i++){
          mp[nums[i]]++;
      }
      int totalSum=0;
      for(int i=0;i<lengthArray;i++){
          if(mp[nums[i]]==1)
              totalSum+=nums[i];
      }
      return totalSum;
    }
};