class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
    int upperBound(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums, target);
        int ub = upperBound(nums, target);
        
        if (lb == nums.size() || nums[lb] != target) {
            return {-1, -1};
        } else {
            return {lb, ub - 1};
        }
    }
};
