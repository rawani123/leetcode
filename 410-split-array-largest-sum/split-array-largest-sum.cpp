class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());  
        int right = accumulate(nums.begin(), nums.end(), 0);  
        
        while (left < right) {
            int mid = left + (right - left) / 2; 
            if (canSplit(nums, k, mid)) {   
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool canSplit(const vector<int>& nums, int k, int maxSum) {
        int currentSum = 0;
        int subarrays = 1;
        
        for (int num : nums) {
            if (currentSum + num > maxSum) {  
                subarrays++;
                currentSum = num;
                if (subarrays > k) {
                    return false;
                }
            } else {
                currentSum += num;
            }
        }
        return true;
    }
};
