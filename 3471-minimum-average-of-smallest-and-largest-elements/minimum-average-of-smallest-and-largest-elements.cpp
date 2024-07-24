class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        double average=INT_MAX;
        while(i<j){
            if(average>((nums[i]+nums[j])/2.0)){
                average=(nums[i]+nums[j])/2.0;
            }
            i++;
            j--;
        }
        return average;
    }
};