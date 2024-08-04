class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        vector<int> subarray_sums;

        // Generate all subarray sums
        for (int start = 0; start < n; ++start) {
            int current_sum = 0;
            for (int end = start; end < n; ++end) {
                current_sum += nums[end];
                subarray_sums.push_back(current_sum);
            }
        }

        // Sort the subarray sums
        sort(subarray_sums.begin(), subarray_sums.end());

        // Calculate the sum from index left to right (1-based index)
        long long result = 0;
        for (int i = left - 1; i < right; ++i) {
            result = (result + subarray_sums[i]) % MOD;
        }

        return result;
    }
};