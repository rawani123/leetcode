class Solution {
public:
    int sumByD(vector<int>& arr, int mid) {
        int sum = 0;
        for (int num : arr) {
            sum += (num + mid - 1) / mid;
        }
        return sum;
    }
   int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low < high) { 
            int mid = low + (high - low) / 2;
            if (sumByD(nums, mid) <= threshold) {
                high = mid;
            } else {
                low = mid + 1; 
            }
        }
        return low;
    }
};